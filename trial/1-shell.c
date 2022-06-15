#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *takeInput()
{
	char *line = NULL;
	ssize_t r;
	size_t len;

	if ((r = getline(&line, &len, stdin)) != -1)
	{
		return (line);
	}
	else
		return (NULL);
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
		execve(a[0], a, NULL);
		if (execve(a[0], a, NULL) < 0)
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
	char *inputString, *args[10];
	int x;

	while (1)
	{
		printf("$ ");
		inputString = takeInput();
		if (inputString == NULL)
			continue;
		x = processString(inputString, args);
		if (x == 1)
			exec_args(args);
	}
	return (0);
}
