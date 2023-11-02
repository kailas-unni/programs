#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

FILE *fp;
char tempstr[50];
char ch;

char kw[32][20] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "int", "goto",
"if", "for", "long", "register", "return", "short", "signed",
"sizeof", "static", "struct", "switch", "typedef", "union",
"unsigned", "void", "volatile", "while"};
char delim[] = {'(', ')', '{', '}', '[', ']', ';', ','};
char operator[] = {'+', '=', '-', '*', '/', '<', '>', '&', '|', '?', '!'};


void appendStr (char *str, char c)
{
    for (;*str;str++);
    *str++ = c; 
    *str++ = 0;
}

void createstring()
{
	strcpy(tempstr, "");
	// appendStr(tempstr,ch);
	// temp = fp;
	while(isalpha(ch) || isdigit(ch) || ch=='_')
	{
		appendStr(tempstr,ch);
		ch = fgetc(fp);
		//fp = temp;
	}
	ungetc(ch, fp);
}

void main()
{
	FILE *fp;
	FILE *temp;
	int check;
	int line=1;
	char fname[50];
	printf("Enter file name : ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if(fp)
		printf("File open");
	else
	{
		printf("Err");
		exit(0);
	}
	
	while((ch=fgetc(fp)) != EOF)
	{
		if(ch=='\n')
			line++;
		check = 0;
		if(ch==' ' || ch=='\t' || ch=='\n')
			continue;
		else if(ch=='/')
		{
			ch = fgetc(fp);
			if(ch == '/')
			{
				printf("\n%d < //", line);
				while((ch=fgetc(fp))!='\n')
				{
					printf("%c", ch);
				}
				printf(" , single line comment >");
				ungetc(ch, fp);
			}
			else if(ch == '*')
			{
				printf("\n%d < /*", line);
				go:
				while((ch=fgetc(fp))!='*')
				{
					printf("%c", ch);
					if(ch=='\n')
					{
						line++;
						printf("%d    ", line);
					}
				}
				ch = fgetc(fp);
				if(ch != '/')
				{
					printf("*");
					ungetc(ch,fp);
					goto go;
				}
				//ungetc(ch,fp);
				printf("*/ , multi line comment >");
			}
			else
				ungetc(ch, fp);
		}
		else if(ch=='#')
		{
			
			printf("\n%d < %c", line, ch);
			while((ch=fgetc(fp)) != '\n')
			{
				printf("%c", ch);
			}
			printf(" , preprocessor directive >");
			line++;
		}
		else if(isdigit(ch))
		{
			printf("\n%d < %c", line, ch);
			temp = fp;
			
			while(isdigit(ch = fgetc(temp)))
			{
				printf("%c", ch);
			}
			if(isalpha(ch))
			{
				strcpy(tempstr, "");
				// appendStr(tempstr,ch);
				// temp = fp;
				while(isalpha(ch) || isdigit(ch) || ch=='_')
				{
					appendStr(tempstr,ch);
					ch = fgetc(fp);
					//fp = temp;
				}
				ungetc(ch, fp);
				printf("%s", tempstr);
				printf(" , invalid identifier >");
			}
			else
			{
				printf(" , number >");
			}
			
		}
		else if(ch=='"')
		{
			printf("\n%d < %c", line, ch);
			while((ch=fgetc(fp)) != '"')
			{
				printf("%c", ch);
			}
			printf("\"");
			if((ch=fgetc(fp))=='"')
				printf("\"");
			else
				ungetc(ch, fp);
			printf(" , string >");
		}
		else if(ch == '\'')
		{
			printf("\n%d < %c", line, ch);
			while((ch=fgetc(fp)) != '\'')
			{
				printf("%c", ch);
			}
			printf("\'");
			if((ch=fgetc(fp))=='\'')
				printf("\'");
			else
				ungetc(ch, fp);
			printf(" , character >");
		}
		else
		{
			check = 0;
			for (int i = 0; i < sizeof(delim) / sizeof(delim[0]); i++)
            {
                if (ch == delim[i])
                {
                    printf("\n%d < %c , delimiter >", line, ch);
                    check = 1;
                    break;
                }
            }
            for (int i = 0; i < sizeof(operator) / sizeof(operator[0]); i++)
            {
                if (ch == operator[i])
                {
                    printf("\n%d < %c , operator >", line, ch);
                    check = 1;
                    break;
                }
            }
			if(check==0 && isalpha(ch))
			{
				strcpy(tempstr, "");
				// appendStr(tempstr,ch);
				// temp = fp;
				while(isalpha(ch) || isdigit(ch) || ch=='_')
				{
					appendStr(tempstr,ch);
					ch = fgetc(fp);
					//fp = temp;
				}
				ungetc(ch, fp);
				for(int i=0; i<32; i++)
				{
					if(!strcmp(tempstr,kw[i]))
					{
						printf("\n%d < %s , keyword >", line, tempstr);
						check = 1;
						break;
					}
				}				
				if(check == 0)
				{
					printf("\n%d < %s , identifier >", line, tempstr);
				}	
			}
		}
	}
	
	fclose(fp);
}
