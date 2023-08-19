#include<stdio.h>
#include<string.h>
int min(int a,int b,int c)
{
    if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
    else if(c<=a&&c<=b) return c;
}
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int main()
{
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    int i,j,n,m;
    for(i=0;str1[i]!='\0';i++);

    n=i;

    for(i=0;str2[i]!='\0';i++);

    m=i;

    int ED[n+1][m+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0||j==0)
            {
                ED[i][j]=max(i,j);
            }
            else
            {
                if(str1[i-1]==str2[j-1])
                {
                    ED[i][j]=ED[i-1][j-1];
                }
                else
                {
                    ED[i][j]=min(ED[i-1][j-1],ED[i-1][j],ED[i][j-1])+1;
                }
            }
        }
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            printf("%d ",ED[i][j]);
        }
        printf("\n");
    }

    i=n;
    j=m;

    while(i>0&&j>0)
    {
        int p=min(ED[i-1][j-1],ED[i-1][j],ED[i][j-1]);
        if(str1[i-1]==str2[j-1])
        {
            i--;
            j--;
        }
        else if(p==ED[i-1][j-1])
        {
            printf("Replace %c with %c\n",str1[i-1],str2[j-1]);
            i--;
            j--;
        }
        else if(p==ED[i-1][j])
        {
            printf("Deleted %c\n",str1[i-1]);
            i--;
        }
        else if(p==ED[i][j-1])
        {
            printf("Inserted %c\n",str2[j-1]);
            j--;
        }
    }
    while(i>0)
    {
        printf("Deleted %c\n",str1[i-1]);
        i--;
    }
    while(j>0)
    {
        printf("Inserted %c\n",str2[j-1]);
        j--;
    }

    return 0;
}
