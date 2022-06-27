#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#define MAX_COMMAND_BUFFER 2147483647
const char *MyShellCommands[] = {"exit", "vars", "set", "del", "cd", NULL};
void *remFirstWord(char *string){
    size_t size = strlen(string);
    size_t i = 0;
    for (i = 0; i < size; i++)
    {
        if (isspace(string[i]) || string[i] == '\n')
        {
            break;
        }
    }
    {
        memmove(string, string + i + 1, size - i + 1);
    }
}
char *getFirstWord(char *string)
{
    char *inputBuffer = (char *)malloc(sizeof(char) * MAX_COMMAND_BUFFER);
    size_t size = strlen(string);
    size_t i = 0;
    for (i = 0; i < size; i++)
    {
        if (isspace(string[i]) || string[i] == '\n' || string[i] == '\0')
        {
            break;
        }
    }
    if (i < 1)
    {
        string = NULL;
        return NULL;
    }
    strncpy(inputBuffer, string, i);
    return inputBuffer;
}
char * currentDir(void)
{
    char buffercwd[FILENAME_MAX];
    return getcwd(buffercwd, FILENAME_MAX);
    
}
size_t findoutCommand(char *firstWorld)
{
    for (size_t i = 0; MyShellCommands[i] != NULL; i++)
    {
        if (strcmp(firstWorld, MyShellCommands[i]) == 0)
        {
            return i;
        };
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    extern char **environ;
    int flag = 0;
    
    
   // memset(*argv,"\0",TMP_MAX*sizeof(char));
    while (flag == 0)
    {
        char *inputBuffer = NULL;
        char *argv[TMP_MAX];            
        char *name = NULL;
        char *value = NULL;
        int status = 0;
        size_t size = 0;
        size_t chars= 0;
        pid_t pid=-1;
        printf("MYSHELL %s > ",currentDir());

        chars = getline(&inputBuffer, &size, stdin);
        inputBuffer[chars-1]='\0';

        name = getFirstWord(inputBuffer);
        int command = findoutCommand(name);
        free(name);

        switch (command)
        {
        case -1: // SYS COM
            pid = fork();
            if(pid == -1){
                fprintf(stderr,"%s \n","Błąd! Nie można utworzyć procesu potomnego!");
                status= -1;
                break;
            }else if(pid > 0 && inputBuffer[chars-2]!='&'){
                int procStatus;
                waitpid(pid, &procStatus,0);
                procStatus=((procStatus) & 0xff00) >> 8;
                printf("Kod zakończenia %i \n", procStatus );
            }else if(pid==0){
                if(inputBuffer[chars-2]=='&'){inputBuffer[chars-2]='\0';}
                name=getFirstWord(inputBuffer);
                value=getFirstWord(inputBuffer);
                remFirstWord(inputBuffer);
                int i = 0;
                while (value!=NULL)
                {
                    argv[i]=value;
                    //printf("%i -> %s \n",i,value);
                    value=getFirstWord(inputBuffer);
                    remFirstWord(inputBuffer);
                    i++;
                }
                argv[i+1]=NULL;
                if(execv(currentDir(),argv)!=0){execvp(argv[0],argv);}
                fprintf(stderr,"%s \n","Bład! Nie ma takiego programu, ani polecenia!");
            }
            break;
        case 0: //exit
            printf("%s \n", "BYE");
            flag=1;
            break;
        case 1://vars
        for (size_t i = 0; environ[i] != NULL; i++)
        {
            printf("%s\n", environ[i]);
        }
        if(environ[0]!=NULL){status = 0;}
        break;
        case 2://set
            remFirstWord(inputBuffer);
            name = getFirstWord(inputBuffer);
            remFirstWord(inputBuffer);
            value = getFirstWord(inputBuffer);
            remFirstWord(inputBuffer);
            status=setenv(name,value,1);
            free(name);
            free(value);
            break;
        case 3://del
            remFirstWord(inputBuffer);
            name = getFirstWord(inputBuffer);
            status = unsetenv(name);
            free(name);
            break;
        case 4://cd
            remFirstWord(inputBuffer);
            name = getFirstWord(inputBuffer);
            status = chdir(name);
            free(name);
            break;
        default:
            break;
        }
        if(status==-1){fprintf(stderr,"%s \n","Błąd! Niepoprawne argumenty polecenia!");}
        free(inputBuffer);
    }
    return 0;
}
