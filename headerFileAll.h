#define N 8
#define page 300
typedef struct
{
    char title[N];
    unsigned long length;

} lesson;
typedef struct
{
    char name[100];
}user;
typedef struct 
{
    user u;
   // struct timedate datTime;
    lesson lessonName;
    unsigned int wpm;
    double accuracy;
}session;



void fileload();
int listLesson(void);
void sreenShowLesson();
int Edit_Distance(char str1[],char str2[],int n,int m);
void beginSession();
void userSelectMenu();
void userFileLoad();
void mainmenu();