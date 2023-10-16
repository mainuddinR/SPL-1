#define N 8
#define page 300
typedef struct
{
    char title[N];
    unsigned long length;

} lesson;

void fileload();
int listLesson(void);
void sreenShowLesson();
int Edit_Distance(char str1[],char str2[],int n,int m);
void beginSession();
