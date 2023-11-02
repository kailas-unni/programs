#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ns, na;
char tran[10][10][10];
int flags[10];
char closure[10][10];
char nfa[10][10][10];

void setflag()
{
	for(int i=0; i<ns; i++)
	{
		flags[i] = 0;
	}
}

void appendStr (char *str, char c)
{
    for (;*str;str++);
    *str++ = c; 
    *str++ = 0;
}

void epsilon(int state, int posstate)
{

    flags[state] = 1;
    char str[5];

	for(int i=0; i<strlen(tran[state][na]); i++)
	{
		if(tran[state][na][i] != '-')
		{
			for(int j=0; j<ns; j++)
			{
				if(flags[j]==0 && (tran[state][na][i]-48)==j)
				{
                    sprintf(str, "%d", j);
					strcat(closure[posstate],str);
					flags[j] = 1;
					epsilon(j,posstate);
				}
			}
		}
	}
}

void main()
{
	int is, nfs, fs[10], tempfs[10];
	printf("Enter no. of states (0,1,2,..): ");
	scanf("%d", &ns);
	printf("Enter no. of alphabets (a,b,c,..): ");
	scanf("%d", &na);
	printf("Enter Initial state : ");
	scanf("%d", &is);
	printf("Enter no. of Final states : ");
	scanf("%d", &nfs);
	printf("Enter Final states :\n");
	for(int i=0; i<nfs; i++)
		scanf("%d", &fs[i]);
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

	printf("\nTransition table :\n\t");
	for(int i=0; i<na; i++)
	{
		printf("%d\t", i);
	}
	printf("E\n");
	for(int i=0; i<nfs; i++)
		tempfs[i] = fs[i];
	for(int i=0; i<ns; i++)
	{
		if(is == i)	printf("->");
		printf("%d", i);
		for(int l=0; l<nfs; l++)
		{
			if(tempfs[l] != -1 && tempfs[l] == i)
			{
				printf("*");
				tempfs[l] = -1;
			}
		}
		printf("\t");
		for(int j=0; j<=na; j++)
		{
			printf("%s\t", tran[i][j]);
		}
		printf("\n");
	}

    char str[5];

    for(int i=0; i<ns; i++)
    {
        setflag();
        sprintf(str, "%d", i);
        strcat(closure[i],str);
        epsilon(i,i);
        printf("\nClosure %d : %s", i, closure[i]);
    }

    //printf("\n%c", closure[0][0]);
    //printf("\n%s\n", tran[closure[0][0]-48][0]);

    for(int i=0; i<ns; i++)
    {
        for(int k=0; k<na; k++)
        {
            setflag();
            char temp2[10]= "";
            for(int j=0; j<strlen(closure[i]); j++)
            {
                char temp[10] = "";   
                strcat(temp, tran[closure[i][j]-48][k]);
                //printf("\nDebug temp : %s", temp);
                for(int l=0; l<strlen(temp); l++)
                {
                    char temp1[10] = "";
                    strcat(temp1, closure[temp[l]-48]);
                    //printf("\nDebug temp1 : %s", temp1);
                    for(int m=0; m<strlen(temp1); m++)
                    {
                        if(flags[temp1[m]-48] == 0)
                        {
                            flags[temp1[m]-48] = 1;
                            appendStr(temp2, temp1[m]);
                        }
                    }
                }
                
            }
            strcat(nfa[i][k], temp2);
        }
    }

    printf("\n\nNFA :\n\t");
	for(int i=0; i<na; i++)
	{
		printf("%d\t", i);
	}
	printf("\n");
	
	/*for(int i=0; i<ns; i++)
	{
		for(int j=0; j<strlen(closure[i]); j++)
		{
			for(int k=0; k<nfs; k++)
			{
				if((closure[i][j]-48) == k)
					tempfs[k] = 
			}
		}
	}
	
	for(int i=0; i<nfs; i++)
	{
		for(int j=0; j<ns; j++)
		{
			for(int k=0; k<strlen(closure[j]); k++)
			{
				if((closure[j][k]-48) == fs[i])
			}
		}
	}*/
	for(int i=0; i<nfs; i++)
		tempfs[i] = fs[i];
		
	int check = 0;
	for(int i=0; i<ns; i++)
	{
		if(is == i)	printf("->");
		printf("%d", i);
		for(int l=0; l<nfs; l++)
		{
			for(int h=0; h<strlen(closure[i]); h++)
			{
				if((closure[i][h]-48) == fs[l])
				{
					printf("*");
				}
			}
		
		}
		printf("\t");
		for(int j=0; j<na; j++)
		{
            if(!strcmp(nfa[i][j],""))
                printf("-\t");
            else
			    printf("%s\t", nfa[i][j]);
		}
		printf("\n");
	}
}
