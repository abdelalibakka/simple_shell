#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Read/write buffer sizes */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Command chaining constants */
#define CMD_NORMAL	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* Conversion constants */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* System getline() usage */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HISTORY_FILE	".simple_shell_history"
#define HISTORY_MAX	4096

extern char **environ;

/**
 * struct liststr - Singly linked list
 * @num: The number field
 * @str: A string
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Contains pseudo-arguments to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: A string generated from getline containing arguments
 * @argv: An array of strings generated from arg
 * @path: A string path for the current command
 * @argc: The argument count
 * @line_count: The error count
 * @err_num: The error code for exit()s
 * @linecount_flag: If on, count this line of input
 * @fname: The program filename
 * @env: Linked list local copy of environ
 * @environ: Custom modified copy of environ from LL env
 * @history: The history node
 * @alias: The alias node
 * @env_changed: On if environ was changed
 * @status: The return status of the last exec'd command
 * @cmd_buf: Address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: Command type (||, &&, ;)
 * @readfd: The fd from which to read line input
 * @histcount: The history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* Pointer to cmd ; chain buffer, for memory management */
	int cmd_buf_type; /* Command type (||, &&, ;) */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - Contains a builtin string and related function
 * @type: The builtin command flag
 * @func: The function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* Function declarations */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int is_cmd(info_t *, char *);
char *dup_chars(char *,
