#include "shell.h"

/**
 * exec_line - executes a line
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exec_line(data_shell *datash)
{
	pid_t cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("Fork failed\n");
		return (0);
	}
	if (cpid == 0)
		execve(datash->input, datash->av, datash->_environ);
	else
		wait(NULL);
	return (0);
}
