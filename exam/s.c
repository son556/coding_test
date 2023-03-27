#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *str)
{
	int 	i;
	int		cnt;
	char	*temp;

	i = 0;
	while (str[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	cnt = i;
	i = -1;
	while (++i < cnt)
		temp[i] = str[i];
	return (temp);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	int		fd;
	char	*path;

	fd = dup(STDIN_FILENO);
	printf("fd: %d\n", fd);
	chdir("~");
	path = getcwd(NULL, 0);
	printf("path: %s\n\n", path);
	if (execve(NULL, NULL, envp) < 0)
		printf("error\n");
	printf("err\n");
	return (0);
}
