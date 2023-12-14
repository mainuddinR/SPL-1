#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "welcome.c"
#include "headerFileAll.h"
#include "timeCounter.h"
#include "RandomStringGenerate.h"
#include "TypingTutor.h"


int main()
{
     welcome();
    //mainmenu();
    fileload();
    //initial();
    userFileLoad();
    //listLesson();
    //sreenShowLesson();
    //beginSession();
    userSelectMenu();
   // listUser();
    return 0;
}