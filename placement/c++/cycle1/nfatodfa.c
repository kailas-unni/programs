#include<stdio.h>
#include<string.h>

void appendstr(char *str, char c)
{
    for(;*str;str++);
    *str++ = c;
    *str++ = 0;
}

void main()
{
    int ns, na;
    char states[20][20], alphabets[20][20];
    char transitions[20][20][20];
    
    printf("Enter the no of states : ");
    scanf("%d", &ns);
    printf("Enter states :\n");
    for(int i=0; i<ns; i++)
    {
        scanf("%s", states[i]);
    }
    printf("Enter the no of alphabets : ");
    scanf("%d", &na);
    printf("Enter alphabets :\n");
    for(int i=0; i<na; i++)
    {
        scanf("%s", alphabets[i]);
    }
    printf("Enter transitions :\n\t");
    for(int i=0; i<na; i++)
        printf("%s\t", alphabets[i]);
    printf("\n");
    for(int i=0; i<ns; i++)
    {
        printf("%s\t", states[i]);
        for(int j=0; j<na; j++)
        {
            scanf("%s", transitions[i][j]);
        }
    }
    printf("NFA :\n\t");
    for(int i=0; i<na; i++)
        printf("%s\t", alphabets[i]);
    for(int i=0; i<ns; i++)
    {
        printf("\n%s\t", states[i]);
        for(int j=0; j<na; j++)
        {
            printf("%s\t", transitions[i][j]);
        }
    }

    //starting
    
    char dfa[20][20][20];
    char newstates[20][20];
    int k=-1;
    for(int i=0; i<ns; i++)
    {
        for(int j=0; j<na; j++)
        {
            char temp[20]="";
            for(int k=0; k<strlen(transitions[i][j]); k++)
            {
                if(transitions[i][j][k]!=',')
                {
                    appendstr(temp,transitions[i][j][k]);
                }
            }
            int check=0;
            if(!strcmp(temp,"-"))
                strcpy(temp,"dead");
            for(int l=0; l<k; l++)
            {
                if(!strcmp(temp,newstates[l]))
                    check=1;
            }
            if(check==0)
                strcat(newstates[++k],temp);
        }
    }

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<na; j++)
        {
            
        }
    }
}