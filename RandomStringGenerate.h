#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//char *day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
//char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

 char random_characters[]={
    ' ','a','b','c','d','e','f',' ','g','h','i','j','k','l','m','n','o','p','q',
    'r','s','t','u','v','w','x','y','z',' ',
     };
 char randomCapitalChar[]={
    ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '
 };
 char number[]={
    '1','2','3','4','5','6','7','8','9','0' };

 int random_char_length=sizeof(random_characters)/sizeof(char);
 int random_Capital_Char_Len=sizeof(randomCapitalChar)/sizeof(char);
 int number_len=sizeof(number)/sizeof(char);

 void rand_string(char *str, int num)
 {
    char mixStr[60];
    strcpy(mixStr,random_characters);
    strcat(mixStr,randomCapitalChar);
    int len=strlen(mixStr);
    for(int i=0;i<num;i++)
    {
        str[i]=mixStr[rand()%(len-1)];
    }
    str[num]='\0';
    printf("%s\n",str);

 }

 void rand_Small(char *str,int num){
    for(int i=0;i<num;i++){
        str[i]=random_characters[rand()%(random_char_length)];
    }
    str[num]='\0';
    printf("%s\n",str);
 }

void rand_Capital(char *str,int num){
    for(int i=0;i<num;i++){
        str[i]=randomCapitalChar[rand()%(random_Capital_Char_Len)];
    }
    str[num]='\0';
    printf("%s\n",str);
 }

void rand_Number(char *str,int num){
    for(int i=0;i<num;i++){
        str[i]=number[rand()%(number_len)];
    }
    str[num]='\0';
    printf("%s\n",str);
 }

void red ()
{
  printf("\033[1;31m");
}
void reset ()
{
  printf("\033[0m");
}

 void typingTest(char *text,int Td)
 {
    time_t t1,t2,t3;
    int c,Tdf;
    int mistakes,numberofchar,i,j,nwords,numberofPage,currentPage,userTypeNofchar;
    mistakes=0;
    numberofchar=strlen(text);
    userTypeNofchar=0;
   
    nwords=0;
    i=0;
   
    t1=time(NULL);

    printf("\n\t\t\t=================\n");
    printf("\n\t\t\tTyping Test Start\n");
    printf("\n\t\t\t=================\n");

    while(i<numberofchar){

        char ch=getch();
        
        t3=time(NULL);
        Tdf=t3-t1;
        if(Td>0&&Tdf==Td){
            printf("\nTime's up!\n");
            break;
        }

        if(ch==27)
        {
                break;
        }
        userTypeNofchar++;
        if(text[i]==ch){
            putch(ch);
            i++;
            if(ch==' '){
                nwords++;
            }
        }
        else{
            red();
            putch(ch);
            reset();
            i++;
            mistakes++;
        }
            
    }
    t2=time(NULL);
    float accuracy;
    int wpm,time_def;

    time_def=t2-t1;
    if(time_def!=0)
    {
        wpm=nwords*60/time_def ;
    }
    if(userTypeNofchar!=0)
    {
        accuracy=(float)(userTypeNofchar-mistakes)*100/userTypeNofchar;
    }
    //printf("\nStarting Time:%d\nEnding time:%d",t1,t2);
    printf("\n\n\nTime:%ds",time_def);
    printf("\nMistake:%d",mistakes);
    printf("\nAccuracy:%f\n",accuracy);
    printf("word per minutes:%d\n",wpm);

     struct tm *date;
    date=localtime(&t1); // history jonno start time 
    printf("Start time [hh:mm:ss]=[%02d:%02d:%02d]",date->tm_hour,date->tm_min,date->tm_sec);
    printf("\n%s, %s %2d, %d",day[date->tm_wday],month[date->tm_mon],date->tm_mday,date->tm_year+1900);

 }
 

