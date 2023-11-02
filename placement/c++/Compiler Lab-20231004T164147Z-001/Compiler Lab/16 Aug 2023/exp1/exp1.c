#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ns, na;
char tran[10][10][10];
int flags[10];

void setflag()
{
	for(int i=0; i<ns; i++)
	{
		flags[i] = 0;
	}
}

void epsilon(int state)
{
	flags[state] = 1;
	
	for(int i=0; i<strlen(tran[state][na]); i++)
	{
		if(tran[state][na][i] != '-')
		{
			for(int j=0; j<ns; j++)
			{
				if(flags[j]==0 && (tran[state][na][i]-48)==j)
				{
					printf(" -> %d", j);
					flags[j] = 1;
					epsilon(j);
				}
			}
		}
	}
}

void main()
{
	
	printf("Enter no. of states (0,1,2,..): ");
	scanf("%d", &ns);
	printf("Enter no. of alphabets (a,b,c,..): ");
	scanf("%d", &na);
	printf("\nEnter transition states (last for epsilon)\n");
	for(int i=0; i<ns; i++)
	{
		for(int j=0; j<=na; j++)
		{
			if(j!=na)
				printf("For %d by accepting %d : ", i, j);
			else
				printf("For %d by accepting E : ", i);
			scanf("%s", tran[i][j]);
		}
	}
	printf("\nTransition states :\n\t");
	for(int i=0; i<na; i++)
	{
		printf("%d\t", i);
	}
	printf("E\n");
	for(int i=0; i<ns; i++)
	{
		printf("%d\t", i);
		for(int j=0; j<=na; j++)
		{
			printf("%s\t", tran[i][j]);
		}
		printf("\n");
	}
	
	int i=0;
	while(i<ns)
	{
		setflag();
		printf("\nEpsilon closure for state %d : %d", i, i);
		epsilon(i);
		i++;
	}
}
