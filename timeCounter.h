#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void counter(int second)
{

int hours,minutes;

    while(second>0){
        hours=second/3600;
        minutes=(second%3600)/60;
        int sec=(second%60);

        printf("\r%02d:%02d:%02d ",hours,minutes,sec);

        fflush(stdout);

        clock_t stop=clock()+CLOCKS_PER_SEC;
        while(clock()<stop){}
        second--;

    }
    printf("Time's up!\n");

}