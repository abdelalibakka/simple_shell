#include "shell.h"

/**
 * get_environ - Returns the string array copy of our environ.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: The string array copy of environ.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		if (info->env)
			free_string_array(info->env);
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * @var: The string env var property.
 *
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t **head = &(info->env);
	list_t *node = *head;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			delete_node_at_index(head, i);
			info->env_changed = 1;
			node = *head;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initializes a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * @var: The string env var property.
 * @value: The string env var value.
 *
 * Return: Always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t **head = &(info->env);
	list_t *node = *head;
	char *p;

	if (!var || !value)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = _strcat(_strcat(_strdup(var), "="), value);
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	buf = _strcat(_strcat(_strdup(var), "="), value);
	add_node_end(head, buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
