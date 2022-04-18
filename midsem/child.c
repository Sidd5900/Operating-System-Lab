#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//arguments in order : 1 boy raj

int main(int argc,char* argv[])
{
	printf("Child # %s: I am a %s, and my name is %s.\n",argv[1],argv[2],argv[3]);
	return 0;
}