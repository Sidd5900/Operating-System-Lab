#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

extern char** environ;

int main(int argc, char* argv[], char* envp[])
{
	/*int i=0;
	while(envp[i]!=NULL)
	{
		printf("%s\n",envp[i]);
		i++;
	}*/
	
    //to get a specific environment variable
	printf("%s\n",getenv("PATH") );

	return 0;
}





/*int main(void) 
{
  char *filepath = "envtest.sh";
  char *const args[] = {filepath, NULL};
  //char *const env[] = {"HOSTNAME=www.xyz.com", "PORT=8080", NULL};
  execve(filepath, args, environ);
  printf("Error : Unable to execute the shell script \n");	
  return 0;
}*/


 