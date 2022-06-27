#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		fprintf(stderr, "Nie podano argumentów!\n");
		return -1;
	}
	if (argc > 2)
	{ 
		fprintf(stderr, "%s", "Proszę podać ciąg cyfr od 1 do 21! Wykryto 2 argumenty, spodziewano się jednego!\n");
		return -1;
	}
	for (int j = 0; j < strlen(argv[1]); j++)
	{
		if (isdigit(argv[1][j]) == 0)
		{
			fprintf(stderr, "Wprowadzono znak zamiast liczby! -> %c", argv[1][j]);
			return -1;
		}
	}
	if (strlen(argv[1]) == 1)
	{
		return (strtol(argv[1], NULL, 10));
	}
	if (strlen(argv[1]) < 1)
	{
		fprintf(stderr, "Niespodziewany błąd!, otrzymano argv[1] o długości 0!");
		return -1;
	}
	int process1PosOfFirstCharacter;
	int process2PosOfFirstCharacter;
	int process1PosOfLastCharacter;
	int process2PosOfLastCharacter;
	if (strlen(argv[1]) % 2 == 0)
	{
		process1PosOfFirstCharacter = 0;
		process2PosOfFirstCharacter = strlen(argv[1]) / 2;
		process1PosOfLastCharacter = process2PosOfFirstCharacter;
		process2PosOfLastCharacter = strlen(argv[1]);
	}
	else
	{
		process1PosOfFirstCharacter = 0;
		process2PosOfFirstCharacter = strlen(argv[1]) / 2 + 1;
		process1PosOfLastCharacter = process2PosOfFirstCharacter;
		process2PosOfLastCharacter = strlen(argv[1]);
	}
	char *process2Arg;
	char *process1Arg;
	process1Arg = (char *)malloc(sizeof(char *) * (process1PosOfLastCharacter - process1PosOfFirstCharacter));
	process2Arg = (char *)malloc(sizeof(char *) * (process2PosOfLastCharacter - process2PosOfFirstCharacter));
	strncat(process2Arg, &argv[1][process2PosOfFirstCharacter], process2PosOfLastCharacter - process2PosOfFirstCharacter);
	strncat(process1Arg, &argv[1][process1PosOfFirstCharacter], process1PosOfLastCharacter - process1PosOfFirstCharacter);

	int process = fork();
	if (process == 0)
	{
		execl(argv[0], argv[0], process1Arg, NULL);
		return -1;
	}
	else
	{
		int process2 = fork();
		if (process2 == 0)
		{
			execl(argv[0], argv[0], process2Arg, NULL);
			return -1;
		}
		else
		{
			int powrot;
			waitpid(process, &powrot, 0);
			powrot = powrot >> 8;
			int powrot2;
			waitpid(process2, &powrot2, 0);
			powrot2 = powrot2 >> 8;
			printf("%d\t%d\t\t%s %d \n", getpid(), process, process1Arg, powrot);
			printf("%d\t%d\t\t%s %d \n", getpid(), process2, process2Arg, powrot2);
			free(process2Arg);
			free(process1Arg);
			return powrot + powrot2;
		}
	}
}