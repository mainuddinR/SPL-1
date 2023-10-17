#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "headerFileAll.h"
#include "TypingTutor.h"
int main()
{
    mainmenu();
    fileload();
    userFileLoad();
    listLesson();
    sreenShowLesson();
    beginSession();
    return 0;
}
