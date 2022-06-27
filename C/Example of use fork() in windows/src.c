#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
int main(int argc, char **argv)
{
	//SAME AS IN LINUX CODE
	if (argc == 1)
	{
		fprintf(stderr, "Nie podano argumentów!\n");
		return 1;
	}
	if (argc > 2)
	{
		fprintf(stderr, "%s", "Proszę podać ciąg cyfr od 1 do 21! Wykryto 2 argumenty, spodziewano się jednego!\n");
		return 1;
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
	int process1ArgPosOfFirstCharacter;
	int process2ArgPosOfFirstCharacter;
	int process1ArgPosOfLastCharacter;
	int process2ArgPosOfLastCharacter;
	if (strlen(argv[1]) % 2 == 0)
	{
		process1ArgPosOfFirstCharacter = 0;
		process2ArgPosOfFirstCharacter = strlen(argv[1]) / 2;
		process1ArgPosOfLastCharacter = process2ArgPosOfFirstCharacter;
		process2ArgPosOfLastCharacter = strlen(argv[1]);
	}
	else
	{
		process1ArgPosOfFirstCharacter = 0;
		process2ArgPosOfFirstCharacter = strlen(argv[1]) / 2 + 1;
		process1ArgPosOfLastCharacter = process2ArgPosOfFirstCharacter;
		process2ArgPosOfLastCharacter = strlen(argv[1]);
	}
	//DEFINE
	STARTUPINFO process1StartupInfo;
	PROCESS_INFORMATION process1ProcessInformation;
	PROCESS_INFORMATION process2ProcessInformation;
	DWORD process1ExitCode = 0;
	DWORD process2ExitCode = 0;
	int sizeOfPathEXE = strlen(argv[0]);
	char *process2Arg;
	char *process1Arg;
	char *process1ArgWithPath;
	char *process2ArgWithPath;
	//MALLOC
	process1ArgWithPath = (char *)malloc(sizeof(char *) * (1 + sizeOfPathEXE + process1ArgPosOfLastCharacter - process1ArgPosOfFirstCharacter));
	process2ArgWithPath = (char *)malloc(sizeof(char *) * (1 + sizeOfPathEXE + process2ArgPosOfLastCharacter - process2ArgPosOfFirstCharacter));
	process1Arg = (char *)malloc(sizeof(char *) * (process1ArgPosOfLastCharacter - process1ArgPosOfFirstCharacter));
	process2Arg = (char *)malloc(sizeof(char *) * (process2ArgPosOfLastCharacter - process2ArgPosOfFirstCharacter));
	//CLEAR JUNK
	ZeroMemory(process1Arg, sizeof(process1Arg));
	ZeroMemory(process2Arg, sizeof(process2Arg));
	ZeroMemory(&process1StartupInfo, sizeof(process1StartupInfo));
	process1StartupInfo.cb = sizeof(process1StartupInfo);
	ZeroMemory(&process1ProcessInformation, sizeof(process1ProcessInformation));
	ZeroMemory(&process2ProcessInformation, sizeof(process2ProcessInformation));
	//PREPARE ARG
	strncat(process2Arg, &argv[1][process2ArgPosOfFirstCharacter], process2ArgPosOfLastCharacter - process2ArgPosOfFirstCharacter);
	sprintf(process2ArgWithPath, "%s %s", argv[0], process2Arg);
	strncat(process1Arg, &argv[1][process1ArgPosOfFirstCharacter], process1ArgPosOfLastCharacter - process1ArgPosOfFirstCharacter);
	sprintf(process1ArgWithPath, "%s %s", argv[0], process1Arg);
	//CREATE PROCESS
	if (!CreateProcessA(
			NULL,
			process1ArgWithPath,
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&process1StartupInfo
	,
			&process1ProcessInformation))
	{
		fprintf(stderr, "Nie można utworzyc procesu (%d)", GetLastError());
		return -1;
	}
	if (!CreateProcessA(
			NULL,
			process2ArgWithPath,
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&process1StartupInfo,
			&process2ProcessInformation))
	{
		fprintf(stderr, "Nie można utworzyc procesu (%d)", GetLastError());
		return -1;
	}
	//GET EXIT CODE
	WaitForSingleObject(process1ProcessInformation.hProcess, INFINITE);
	GetExitCodeProcess(process1ProcessInformation.hProcess, &process1ExitCode);
	WaitForSingleObject(process2ProcessInformation.hProcess, INFINITE);
	GetExitCodeProcess(process2ProcessInformation.hProcess, &process2ExitCode);
	//PRINT
	printf("%d\t%u\t\t%s %d \n", _getpid(), process1ProcessInformation.dwProcessId, process1Arg, process1ExitCode);
	printf("%d\t%u\t\t%s %d \n", _getpid(), process2ProcessInformation.dwProcessId, process2Arg, process2ExitCode);
	//CLOSE AND REMOVE JUNK
	CloseHandle(process1ProcessInformation.hProcess);
	CloseHandle(process1ProcessInformation.hThread);
	CloseHandle(process2ProcessInformation.hProcess);
	CloseHandle(process2ProcessInformation.hThread);
	free(process1Arg);
	free(process2Arg);
	free(process1ArgWithPath);
	free(process2ArgWithPath);
	//END
	return process1ExitCode + process2ExitCode;
}