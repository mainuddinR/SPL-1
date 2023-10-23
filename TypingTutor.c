#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
//#include "welcome.c"
#include "headerFileAll.h"
#include "TypingTutor.h"

int main()
{
    //welcome();
    mainmenu();
    fileload();
    userFileLoad();
    listLesson();
    sreenShowLesson();
    beginSession();
    return 0;
}