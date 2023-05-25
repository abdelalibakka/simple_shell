#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>


extern char **environ;

char *_getenv(const char *varname);
void _putchar(char c);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void *_realloc(void *ptr, unsigned int size);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
ssize_t _getline(char **lineptr, size_t *n, char *stream);
char *my_strtok(char *str, char *delim);


void execute_cmd(char **args, char **argv, char **env,
		int atty, char *buf1, char *buf2, char *buf3);
char **fill_arr_by_tokens(char *buf_copy, char **args);
void forking(char *args[], char **env);
void free_arr_of_strs(char **arr);
unsigned int get_num_tokens(char *buf);
char *get_path(char *cmd);
void is_input_env(char **args);
void is_input_exit(char **args, char *buf1, char *buf2, char *buf3);
int is_path(char *cmd);
char *read_line();
char **split_dirs(char *env_dirs);
int change_dir(char **args);
int check_built_n(char **args, char **env, char *buf1, char *buf2, char *buf3);
void set_env(char **args, char **env);
void unset_env(char **args, char **env);
void free_all(char **args, char *buf1, char *buf2, char *buf3);
void handle_sig(int sig);

#endif
