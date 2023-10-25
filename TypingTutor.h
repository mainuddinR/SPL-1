FILE *fllist; //lesson number and name list
FILE *flesson; 
FILE *FileUserList; //user list
FILE *userAloneFile;
int nusers;
lesson cl;
user currentUser;
session cp; //current persion stat add;
temp pass ;
char *text;
int count=0;
void initial()
{
    cp.accuracy=0.0;
    cp.wpm=0;
}
void fileload()
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
        getchar();
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

void red ()
{
  printf("\033[1;31m");
}
void reset ()
{
  printf("\033[0m");
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
    printf("word per minutes:%d\n",wpm);
     struct tm *date;
    date=localtime(&t1); // history jonno start time 
    printf("Start time [hh:mm:ss]=[%02d:%02d:%02d]",date->tm_hour,date->tm_min,date->tm_sec);
    printf("\n%s, %s %2d, %d",day[date->tm_wday],month[date->tm_mon],date->tm_mday,date->tm_year+1900);
    cp.u=currentUser;
    cp.accuracy=accuracy;
    cp.wpm=wpm;
   // cp.datTime=*date;
}

void login()
{
    char us[20];
    char password[20];
    printf("USER ID:\n");
    scanf("%s",currentUser.userID);
    getchar();
    sprintf(us,"%s.dat",currentUser.userID);
   // strcpy(us,currentUser.userID);
    if( (userAloneFile = fopen(us,"r+b")) == NULL )	/*opened for the beginSession() to write session details*/
	{
		printf("\n\nInvalid UserID");
		printf("\npress any key to continue...");
		getch();
		return;
	}
    printf("Password:\n");
    //gets(pass.name);
	int i=0; 
	do{ 
		password[i]=getch(); 
        //scan("%c",&password[i]);
		if(password[i]!='\r'){ 
			printf("*"); 
		} 
		i++; 
	}while(password[i-1]!='\r'); 
    password[i-1]='\0';
    char rPass[20];
    fread(&rPass,sizeof(temp),1,userAloneFile);
    if((strcmp(rPass,password))==0)
    {
        printf("\nLogin Success..\n");
        sleep(1);
        mainmenu();
       // printf("press any key to continue...\n");
		// getch();
		return;
    }
    else{
        printf("wrong Password\n");
        printf("try Again..\n");
        count++;
        if(count==3) return;
        login();
    }


   /* while(1)
    {
         gets(pass);
         if(strlen(pass)>=8){
            break;
         }
         printf("pleace use 8+ character")
    }*/
   
    return ;
}

void createUser()
{
    char userFileName[20];
   // char pass[20];
    fseek(FileUserList,0,SEEK_SET);
    nusers++;
    fwrite(&nusers,sizeof(int),1,FileUserList);//Update no.of user

    printf("\nEnter your name :\n");
    scanf("%s",currentUser.name);

    printf("Enter your username :\n");
    scanf("%s",currentUser.userID);
    getchar();

    printf("Enter your Password(More than 8 Characters) :\n");
    gets(pass.flag);

    fseek(FileUserList,0L,SEEK_END); //0L meanas No offset orthad END thekei suru
    fwrite(&currentUser,sizeof(user),1,FileUserList);// UserID and name add file

    sprintf(userFileName,"%s.dat",currentUser.userID);
    userAloneFile=fopen(userFileName,"wb");//create file
    //fclose(userAloneFile);
   // userAloneFile=fopen(userFileName,"r+b");
    fseek(userAloneFile,0L,SEEK_SET);
    fwrite(&pass,sizeof(temp),1,userAloneFile);
    fclose(userAloneFile);
    userAloneFile=fopen(userFileName,"r+b");
    //printf("\n\n\n\nUser file created\n press any key to continue...");
	//getch();
    printf("\n\n sign Up complete!\n\n");
    sleep(1);
     login();///aber login kore add hoibe
}

int lisrUser()
{
    int i=0;
    char userfilename[100];
    if(nusers==0){
        printf("\n\nNo users exist...");
        printf("\npress any key to continue..");
        getch();
        return -1;
    }
    printf("\nNumber of users: %d",nusers);
    fseek(FileUserList,sizeof(int),SEEK_SET);
    for(i=1;i<=nusers;i++)
    {
        fread(&currentUser,sizeof(user),1,FileUserList);
        printf("\n(%d) %s",i,currentUser.name);
    }
    printf("\nSelect a user (please type the name): ");
	scanf(" %s",currentUser.name);
	sprintf(userfilename,"%s.dat",currentUser.name);
    if((userAloneFile=fopen(userfilename,"r+b"))==NULL)
    {
        printf("\n\nInvalid filename\n");
		printf("press any key to continue...\n");
		getch();
		return -1;
    }
    printf("\nSuccess!!\n");
    printf(" press any key to continue...");
	getch();
	return 0;
}

void userSelectMenu()
{
    /*char *menuitem[4]={"\n\n\r(1)Log In",
                        "\n\n\r(2)Sing Up",
                        "\n\n\r(3)Back",
                        "***USER SELECTION MENU***"};*/
    int c,extended,option=0;
    //printf("\n\r%26s%c T Y P I N G  T E S T E R %c","",16,17);
    printf("\n\n(1)LogIn.\n");
    printf("(2)SingUp.\n\n");
    printf("Enter your choice: ");
     scanf("%d", &option);
     switch(option){
        case 1:
        login();
        break;
        case 2:
        createUser();
        break;
        default:
        printf("choice mismatch, Again try!!");
        userSelectMenu();
     }

}

void mainmenu()
{
     while (1) {
        system("cls"); // Clear the screen

        printf("Welcome to the Typing Tutor!\n");
        printf("Main Menu:\n");
        printf("1. Typing Test\n");
        printf("2. Statistics\n");
        printf("3. View User Records\n");
        printf("4. About\n");
        printf("5.Quit\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listLesson();
                sreenShowLesson();
                beginSession();
                break;
            case 2:
               // viewInstructions();
                break;
            case 3:
                //viewHighScores();
                break;
            case 4:
                break;
            case 5:
                printf("Thank you for using Typing Tutor. Goodbye!\n");
                //exit(0);
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
        if(choice==5||choice==1)
        {
             break;
        }
           
    }
}
void userFileLoad()
{
    FILE *fstat;
    lesson l;
    if((FileUserList=fopen("userList.dat","rb+"))==NULL)//if fine does not exist
    {
        printf("\n\nFile dose not exist.\n Creating new file...\n");
        FileUserList=fopen("userList.dat","wb"); //then creat new file
        nusers=0;//no user
        fwrite(&nusers,sizeof(int),1,FileUserList);
        fclose(FileUserList);
        FileUserList=fopen("userList.dat","rb+");

    }
    else{
        fread(&nusers,sizeof(int),1,FileUserList);
    }
    if((fstat=fopen("stat.dat","rb"))==NULL)
    {
        fstat=fopen("stat.dat","wb");
        fclose(fstat);
    }
    else
    {
        fclose(fstat);
    }

}
