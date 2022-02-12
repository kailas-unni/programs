#include <stdio.h>
int arr[10][10];
int temp[30][2];
int row, col;
void display()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}
void make()
{
    int check = 0, count=0, m=0, i, j, t=3;
    printf("\nDay 0\n");
    display();
    while (1)
    {
        m=0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (arr[i][j] == 2)
                {
                    if (arr[i][j - 1] == 1 && i >= 0 && j >= 0)
                    {
                        temp[m][0] = i;
                        temp[m][1] = j-1;
                        m++;
                        check++;
                    }
                    if (arr[i][j + 1] == 1 && i >= 0 && j >= 0)
                    {
                        temp[m][0] = i;
                        temp[m][1] = j+1;
                        m++;
                        check++;
                    }
                    if (arr[i - 1][j] == 1 && i >= 0 && j >= 0)
                    {
                        temp[m][0] = i-1;
                        temp[m][1] = j;
                        m++;
                        check++;
                    }
                    if (arr[i + 1][j] == 1 && i >= 0 && j >= 0)
                    {
                        temp[m][0] = i+1;
                        temp[m][1] = j;
                        m++;
                        check++;
                    }
                }
            }
        }
        if(check==0)
        {
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                {
                    if(arr[i][j] == 1)
                        check=1;
                }
                if(check == 1)
                    printf("Not all oranges cheenju!!");
                else
                    printf("Days taken %d", count);
                return;
        }
        else
        {
            m=0;
            while(check!=0)
            {
                i = temp[m][0];
                j = temp[m][1];
                arr[i][j] = 2;
                m++;
                check--;
            }
            count++;
            check=0;
        }
        printf("\nDay %d\n", count);
        display();
    }
}
void main()
{
    int days;
    printf("Enter row and col size of matrix :\n");
    scanf("%d %d", &row, &col);
    printf("Enter matrix elements :\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);
    printf("Entered matrix is :\n");
    display();
    make();
    printf("\n");
}