#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//#include<string.h>
#include<time.h>
#define N 8
#define page 300
//#define CLRSCR  window(1,1,80,25);textbackground(0);clrscr();
FILE *fllist;
FILE *flesson;
typedef struct
{
    char title[N];
    unsigned long length;

} lesson;
lesson cl;
char *text;
void fileload(void)
{
    lesson l;
    int n=4,i;
    fllist=fopen("ListOfLesson.dat","wb");
    fwrite(&n,sizeof(int),1,fllist);
    strcpy(l.title,"ATOZ");
    l.length=449;
    fwrite(&l,sizeof(lesson),1,fllist);
    strcpy(l.title,"HOOKS");
    l.length=1710;
    fwrite(&l,sizeof(lesson),1,fllist);
    strcpy(l.title,"RADIO");
    l.length=1717;
    fwrite(&l,sizeof(lesson),1,fllist);
    strcpy(l.title,"TYPE");
    l.length=517;
    fwrite(&l,sizeof(lesson),1,fllist);
    fclose(fllist);
}
int listLesson(void)
{
    int n,option;
    char filename[N+3+1];
    lesson l1,l2,l3,l4;
    int c,i=0;
    ///CLRSCR
    fllist=fopen("ListOfLesson.dat","rb");
    fread(&n,sizeof(int),1,fllist);
    printf("\nnumber of lesson: %d",n);
    fread(&l1,sizeof(lesson),1,fllist);
    printf("\n(1) %.8s %ld characters",l1.title,l1.length);
    fread(&l2,sizeof(lesson),1,fllist);
    printf("\n(2) %.8s %ld characters",l2.title,l2.length);
    fread(&l3,sizeof(lesson),1,fllist);
    printf("\n(3) %.8s %ld characters",l3.title,l3.length);
    fread(&l4,sizeof(lesson),1,fllist);
    printf("\n(4) %.8s %ld characters",l4.title,l4.length);
    fclose(fllist);

    printf("\nSelect your lesson (1,2,3,4): ");
    scanf("%d",&option);
    if(option==1)
    {
        cl=l1;
    }
    else if(option==2)
    {
        cl=l2;
    }
    else if(option==3)
    {
        cl=l3;
    }
    else if(option==4)
    {
        cl=l4;
    }
    else
    {
        cl=l1;
    }
    sprintf(filename,"%s.txt",cl.title);
    flesson = fopen(filename,"r");
    if( flesson == NULL)
    {
        printf("\n\aLesson file not found!!!");
        printf("\npress any key to continue...");
        getch();
        return -1;
    }
    text=malloc(sizeof(char)*cl.length);
    if( text == NULL )
    {
        printf("\n\n\aOUT OF MEMORY!!!");
        getch();
    }
    while( (c=getc(flesson)) != EOF)
    {
        text[i]=c;
        i++;
    }

    fclose(flesson);

    printf("\a");
    return 0;
}
void sreenShowLesson()
{
    int i=0;
    printf("%s\n",cl.title);
    while(i<cl.length)
    {
        printf("%c",text[i]);
        i++;
    }

}
void beginSession()
{
    time_t t1,t2;
    int c;
    int mistakes,numberofchar,i,j,nwords,numberofPage,currentPage,userTypeNofchar;
    mistakes=0;
    numberofchar=cl.length;
    userTypeNofchar=0;
    currentPage=1;
    nwords=0;
    i=0;
    numberofPage=numberofchar/(page)+1;
    t1=time(NULL);
    char str1[26],str2[26];
    int a=0,b=0;
    int flog1=0,flog2=0;
    printf("\n\t\t\t=================\n");
    printf("\n\t\t\tTyping Test Start\n");
    printf("\n\t\t\t=================\n");
    while(i<numberofchar)
    {
        while(j<page)
        {
            c=getch();
            /* if(c==32||c=='\t'||c=='\r'){
                 str2[a]='\0';
                 a=0;
             }
             else{
                 str2[a]=(char)c;
                 a++;
             }*/
            if(c==text[i])
            {
                putch(c);
                if(c==32||c=='\t'||c=='\r')
                {
                    str2[a]='\0';
                    str1[b]='\0';
                    b=0;
                    a=0;
                    int x=Edit_Distance(str1,str2,strlen(str2),strlen(str1));
                    if(x!=0)
                    {
                        red();
                        printf("{wrong} ");//kono vule kisu type korle wrong and seta red wrong a dekhabe .
                        reset();
                    }

                }
                else
                {
                    str2[a]=(char)c;
                    a++;
                    str1[b]=(char)c;
                    b++;
                }

                i++;
                j++;
                userTypeNofchar++;
                if(c==32||c=='\t'||c=='\r')
                {
                    nwords++;
                }
            }
            else if(c==27)
            {
                i=numberofchar;
                str1[b]='\0';
                b=0;
                break;
            }
            else
            {
                putch(c);
                if(c==32||c=='\t'||c=='\r')
                {
                    str2[a]='\0';
                    a=0;
                    flog1=1;
                }
                else
                {
                    str2[a]=(char)c;
                    a++;
                }

                mistakes++;
                if(text[i]==32)
                {
                    //no change;//"the" poriborte "theeeeee" type korle worng dekhano.orThad 3 character poriborte besi character type korle.
                    str1[b]='\0';
                    b=0;
                    flog2=1;
                }
                else if(c==32&&text[i]!=32)
                {
                    //no change;
                    str1[b]=text[i];
                    b++;
                    while(text[i]!=32) //handle EX:"quick" poriborte "qu","quk",orThad 5 character kom type korle wrong dekhano.
                    {
                        i++;
                    }
                    if(text[i]==32)
                    {
                        i++;
                        str1[b]='\0';
                        b=0;
                        flog2=1;
                    }
                }
                else
                {
                    str1[b]=text[i];
                    b++;
                    i++;
                }

                j++;
                userTypeNofchar++;
                if(c==32||c=='\t'||c=='\r')
                {
                    nwords++;
                }
                if(flog1==1&&flog2==1) //"dog" poriborte jodi "dg" type kori thkhon wrong dekhabe arthad kom character type korle wrong dekhabe
                {
                    int y=Edit_Distance(str1,str2,strlen(str2),strlen(str1));
                    if(y!=0)
                    {
                        red();
                        printf("{wrong} ");
                        reset();
                    }
                    flog1=0;
                    flog2=0;
                }

            }
        }
        if(c==27) break;
        j=0;
        currentPage++;
        if(currentPage>numberofPage)
            break;
    }
    t2=time(NULL);
    float accuracy;
    int wpm,time;
    time=t2-t1;
    if(time!=0)
    {
        wpm=nwords*60/time ;
    }
    if(userTypeNofchar!=0)
    {
        accuracy=(float)(userTypeNofchar-mistakes)*100/userTypeNofchar;
    }
    //printf("\nStarting Time:%d\nEnding time:%d",t1,t2);
    printf("\nTime:%ds",time);
    printf("\nMistake:%d",mistakes);
    printf("\nAccuracy:%f\n",accuracy);
    printf("\word per minutes:%d\n",wpm);
}
int Edit_Distance(char str1[],char str2[],int n,int m)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    if(str1[n-1]==str2[m-1])
    {
        return Edit_Distance(str1,str2,n-1,m-1);
    }
    else
    {
        int k;
        k=1+minv(Edit_Distance(str1,str2,n-1,m-1),Edit_Distance(str1,str2,n,m-1),Edit_Distance(str1,str2,n-1,m));
        return k;
    } ///n-1,m-1 replace;
    ///n,m-1 insert;
    ///n-1,m  deleted;
}
int minv(int a,int b,int c)
{
    if(a<=b&&a<=c)
    {
        return a;
    }
    else if(b<=a&&b<=c)
    {
        return b;
    }
    else if(c<=a&&c<=b)
    {
        return c;
    }
}

void red ()
{
  printf("\033[1;31m");
}
void reset ()
{
  printf("\033[0m");
}

int main()
{
    fileload();
    listLesson();
    sreenShowLesson();
    beginSession();
    return 0;
}
