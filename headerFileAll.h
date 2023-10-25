#define N 8
#define page 300
typedef struct
{
    char title[N];
    unsigned long length;

} lesson;
typedef struct
{
    char name[20];
    char userID[20];
} user;

typedef struct 
{
    char flag[20];
}temp;


/*struct tm {
   int tm_sec;         // seconds,  range 0 to 59          
   int tm_min;         // minutes, range 0 to 59           
   int tm_hour;        // hours, range 0 to 23             
   int tm_mday;        // day of the month, range 1 to 31  
   int tm_mon;         // month, range 0 to 11             
   int tm_year;        // The number of years since 1900   
   int tm_wday;        // day of the week, range 0 to 6    
   int tm_yday;        // day in the year, range 0 to 365  
   int tm_isdst;       // daylight saving time             	
};*/
typedef struct 
{
    //name userName;
    user u;
    struct tm datTime;
    lesson lessonName;
    unsigned int wpm;
    double accuracy;
}session;
char *day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};


void fileload();
int listLesson(void);
void sreenShowLesson();
int Edit_Distance(char str1[],char str2[],int n,int m);
void beginSession();
void userSelectMenu();
void userFileLoad();
void mainmenu();