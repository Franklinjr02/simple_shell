#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int takeInput(char *str)
{
	char *line = NULL;
	ssize_t r;
	size_t len;

	if ((r = getline(&line, &len, stdin)) != -1)
	{
		strcpy(str, line);
		return (0);
	}
	else
		return (1);
}
int processString(char *str, char *a[])
{
	int i;

	a[0] = strtok(str, " ");
	for (i = 1; i < 10; i++)
	{
		a[i] = strtok(NULL, " ");
		if (a[i] == NULL)
			break;
		if (strlen(a[i]) == 0)
			i--;
	}
	return (1);
}
void exec_args(char *a[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: ");
		return;
	}
	else if (pid == 0)
	{
		if (execve(a[0], &a[0], NULL) == -1)
		{
			printf("No such file or directory\n");
		}
		exit(0);
	}
	else
		wait(NULL);
}
/**
 * main - the main function
 *
 * Return: int
 */

int main(void)
{
	char inputString[100], *args[10];
	int x;

	while (1)
	{
		printf("$ ");
		if (takeInput(inputString))
			continue;
		x = processString(inputString, args);
		if (x == 1)
			exec_args(args);
	}
	return (0);
	/*pid_t p;

	p = fork();
	if (p == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (p == 0)
	{
		{
			printf("$ ");
			if (execve(line, &line, NULL) == -1)
			{
				perror("Error");
			}
			wait(NULL);
		}
	}
	free(line);
	return (0);*/
}
