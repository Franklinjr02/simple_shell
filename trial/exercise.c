#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes the command "ls -l /tmp" in 5
 * different child processes
 *
 * Return: 0
 */

int main()
{
	int i, status;
	pid_t pid[5];
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			printf("error");
			return (1);
		}
		else if (pid[i] == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	printf("back to the parent");
	/*for (i = 0; i < 5; i++)
	{
		cpid = waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			printf("Child %d terminated with status: %d\n",
					cpid, WEXITSTATUS(status));
	}*/
	return (0);
}
