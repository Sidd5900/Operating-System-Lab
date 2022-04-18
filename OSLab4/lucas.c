#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	int n;
	scanf("%d",&n);
	int lucas[n];
	lucas[0]=2;
	lucas[1]=1;
	for(int i=2;i<n;i++)
	{
		lucas[i]= lucas[i-1] + lucas[i-2];
	}

	for(int i=0;i<n;i++)
		printf("%d ",lucas[i] );
	return 0;
}