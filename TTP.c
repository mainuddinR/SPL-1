#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "TdfVarTTP.h"
#include "TTP.h"
int main()
{
    fileload();
    listLesson();
    sreenShowLesson();
    beginSession();
    return 0;
}
