/**
 * struct builtins - structure for built-in commands
 * @name: name of the command
 * @func: function pointer to the command
 */
{
	char *name;
	int (*func)(char **args, char **env);
} builtins_t;

/**
 * print_env - prints the current environment
 * @args: the arguments passed to the function
 * @env: the environment variables
 *
 * Return: Always returns 0
 */
int print_env(char **args, char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
		_putchar('\n');
	}
	return (0);
}

/**
 * print_exit_error - prints an error message if exit fails
 * @args: the arguments passed to the function
 * @env: the environment variables
 *
 * Return: Always returns -1
 */
int print_exit_error(char **args, char **env)
{
	perror(args[0]);
	return (-1);
}

/**
 * exit_shell - exits the shell
 * @args: the arguments passed to the function
 * @env: the environment variables
 *
 * Return: Always returns -1
 */
int exit_shell(char **args, char **env)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		exit_status = _atoi(args[1]);
	}
	exit(exit_status);
}
