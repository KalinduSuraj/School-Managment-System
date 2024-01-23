#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
//#include <math.h>



int grade;
int stdID;
int log;

// using for enter the user name and password
int login()
{
    studentBots();

   int rValue;

    printf("1.Principal login\n"
           "2.Teacher login\n");
    printf("\nEnter login type:");
    scanf("%d",&log);

    //principal login
    if (log == 1)
    {
       rValue=P_Log();
       return rValue;
    }
    else if(log == 2)
    //Teacher login
    {
       rValue=T_Log();
       return rValue;
    }
    else
    //for invalid input
    {
        system("cls");
        printf("Invalid input!... Please try again\n\n\n");
        login();
    }


}

//teacher login
int T_Log()
{
    studentBots();
    char uName[10],pw[10],UName2[10],pw2[10];
    int x=0,i=0,j=0;

    printf("\tEnter User Name  : ");
    scanf("%s",&uName);
    printf("\n\tEnter Password   : ");
    while ((pw[i] = _getch()) != '\r')
    {  // Read until Enter is pressed
        printf("*");
        i++;
    }
    pw[i] = '\0';  // Add null terminator

    FILE*UserAcc;
    UserAcc=fopen("UserPW.txt","r");

    while((fscanf(UserAcc,"%s %s",&UName2,&pw2)==2))
    {
        x++;
    }
     fclose(UserAcc);

     UserAcc=fopen("UserPW.txt","r");

    while((fscanf(UserAcc,"%s %s",&UName2,&pw2)==2))
    {

            if(strcmp(UName2,uName)==0)
            {
                if (strcmp(pw2,pw)==0)
                {

                   logsucc();
                    sleep(2);
                    system("CLS");

                    break;
                }
                else
                {
                   system("CLS");
                   logfail();

                   sleep(2);
                   system("CLS");

                   T_Log();
                }
            }
            else
            {
                j++;
                if(x==j)
               {
                    system("CLS");
                    logfail();

                   sleep(2);
                   system("CLS");

                   T_Log();
               }
               else
               {
                 continue;

               }


            }


    }

    fclose(UserAcc);

    choose_grade();
    return 2;

}

//principal login
int P_Log()
{
    studentBots();

    char UName[]="user";
    char PW[]="1111";
    char uName[10];
    char pw[10];

    int i=0;

    printf("\t Enter user name  : ");
    scanf("%s",&uName);
    printf("\t Enter password   : ");
    while ((pw[i] = _getch()) != '\r')
        {  // Read until Enter is pressed
        printf("*");
        i++;
        }
    pw[i] = '\0';  // Add null terminator

                    if (((strcmp(UName,uName))==0)&&((strcmp(PW,pw))==0))
                    {
                        logsucc();
                        sleep(2);
                        system("CLS");

                        Principal_Main_Menu();
                    }
                    else
                    {
                        logfail();
                        sleep(2);
                        system("CLS");
                        P_Log();
                    }

    return 1;

}

//first menue for principle login
void Principal_Main_Menu()
{
    studentBots();

    int Type;

    setColor(FOREGROUND_INTENSITY |  FOREGROUND_BLUE);
    printf("---------------Menue---------------");
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\n\n\t (1) Create Teacher Login \n\t (2) Choose Grade \n\t (3) Back \n\n");
    printf("Enter Your Choose : ");
    scanf("%d",&Type);
    system("CLS");

    if (Type==1)
        {
            Create_Teacher_Login();
        }
    else if (Type==2)
        {
           choose_grade();
        }
    else if(Type==3)
        {
            system("CLS");
            main();
        }
    else
        {
            system("CLS");
            printf("Invalid input!...Please try again\n\n\n");
            sleep("2");
            system("CLS");
            Principal_Main_Menu();

        }
}

//creating teacher login
void Create_Teacher_Login()
{

    studentBots();


    char Uname[10],PW[10],PW2[10];
    printf("\n Create User Name       : ");
    scanf(" %s",&Uname);

    printf("\n Create your password   : ");
    scanf("%s",&PW);
    printf("\n Re Enter your password : ");
    scanf("%s",&PW2);

    FILE*UserPW;
    UserPW=fopen("UserPW.txt","a");

    if (strcmp(PW,PW2)==0)
    {
        fprintf(UserPW,"%s\n%s\n",Uname,PW);
        printf("Account created");
        Principal_Main_Menu();
        system("CLS");
    }
    else
    {
        system("CLS");
        printf("Password was incorrect please enter your password!!\n");
        sleep(2);
        system("CLS");
        Create_Teacher_Login();
    }
    fclose(UserPW);
}


//Input Grade
void choose_grade()
{
    studentBots();


    printf("\nEnter Grade: ");
    scanf("%d",&grade);
}

//input student number
void studentNum()
{
    studentBots();


    printf("Enter student number:");
    scanf("%d",&stdID);
}

//for display the options
int menue(int log)
{

    studentBots();

    int num;
    //principal login options
    if (log==1)
    {
          setColor(FOREGROUND_INTENSITY |  FOREGROUND_BLUE);
          printf("---------------Activity List---------------\n");
          setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

          printf(
           "\n\t (1).Add new student\n"
           "\t (2).Add student marks\n"
           "\t (3).Add student co-Activities\n"
           "\t (4).Student grade list\n"
           "\t (5).Student hirachy\n"

           "\t (0).Exit\n"
           "\t (99).Back\n");


        printf("\nEnter your choice:");
        scanf("%d",&num);

         if ((num>=0)&&(num<=7)||num==99)
        {
            return num;
        }
        else
        {
        system("CLS");
        printf("Invalid input!...Please try again\n\n\n");
        sleep("2");
        system("CLS");
        menue(log);
        }
    }
    else{

          setColor(FOREGROUND_INTENSITY |  FOREGROUND_BLUE);
          printf("---------------Activity List---------------\n");
          setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    //Teacher login options
        printf(
           "\n\t (1).Add new student\n"
           "\t (2).Add student marks\n"
           "\t (3).Add student co-Activities\n"
           "\t (0).Exit\n"
           "\t (99).Back\n");

        printf("\nEnter your choice:");
        scanf("%d",&num);
        if ((num>=0)&&(num<=7)||num==99)
        {
            return num;
        }
        else
        {
        system("CLS");
        printf("Invalid input!...Please try again\n\n\n");
        sleep("2");
        system("CLS");
        menue(log);
        }
    }


}

//for new student adding option
int newStudent()
{

    studentBots();


    char filename[50],name[60],bDay[12],aDay[12],gName[60],op;
    int x;

    printf("Create Student index number:");
    scanf("%d",&stdID);

    //creating file in the folder
    sprintf(filename,"%d/%d.txt",grade,stdID);

    FILE*addStu;
    addStu=fopen(filename,"a");

    if (addStu== NULL)
    {
        printf("error");
    }
    else
    {
         printf("student file creation is success");
    }

    printf("\nEnter full name:");
    scanf(" %[^\n]",&name);
    printf("\nEnter date of birth (YYYY/MM/DD):");
    scanf(" %s",&bDay);
    printf("\nEnter date of Admission (YYYY/MM/DD):");
    scanf(" %[^\n]",&aDay);
    printf("\nEnter gardian name:");
    scanf(" %s",&gName);

    printf("%s",name);
    printf("%s",bDay);

    fprintf(addStu,"Full name: %s \nDate of birth: %s \nDate of admission: %s \nGardian name: %s",name,bDay,aDay,gName);

    printf("Do you want to add more student(Y/N): ");
    scanf(" %c",&op);

    op =toupper(op);

    if(op == 'Y')
    {
        system("cls");
        newStudent();
    }
    else if(op == 'N')
    {
        system("cls");
        printf("\n1.Back to main menue "
               "\n2.Exit");
        scanf(" %d",&x);
        if (x==1)
        {
            system("cls");
            menue(log);
        }else
        {
            return 0;
        }


    }
    else
    {
        printf("invalid input!");
        return 0;
    }


}

//for get student marks
int getMarks()
{

    studentBots();

    int marks[13],range;
    char sub[12][10]={"Sinhala","Maths","Science","Buddhism","English","History","Geogrophy","Civics","Art","Ict   ","Commerce","Tamil"};

    printf("Enter Student index number:");
    scanf("%d",&stdID);


    if (grade>=1&&grade<=5)
    {
        range=5;
        for(int i=0;i<5;i++)
    {
        printf("Enter your %s marks: \n",sub[i]);
        scanf("%d",&marks[i]);

        printf("\n%d",marks[i]);
    }


    }
    else if(grade>=6 && grade <=9)
    {
        range=13;
       for(int i=0;i<13;i++)
    {
        printf("Enter your %s marks: \n",sub[i]);
        scanf("%d",&marks[i]);

        printf("\n%d",marks[i]);
    }

    }
    else
    {
        range=9;
       for(int i=0;i<13;i++)
    {
        printf("Enter your %s marks: \n",sub[i]);
        scanf("%d",&marks[i]);

        printf("\n%d",marks[i]);
    }

    }
    sum(marks,range);
    gradeMaking(sub,marks,range);





}

//for making grade for marks and write it to text file

void gradeMaking(char sub[12][10], int mark[],int range)
{

    studentBots();


    char fileMarks[50];


    //creating file in the folder
    sprintf(fileMarks,"%d/%d_Marks.txt",grade,stdID);

    FILE*addMarks;
    addMarks=fopen(fileMarks,"a");


    char grd;


 for(int i=0;i<range;i++)
 {

 // choose grade
     if(mark[i]>=75 && mark[i]<=100)
        {
           // printf("\nSubject %s\t--> Grade is ",sub[i]);
           // printf("A");
            grd='A';
        }
        else if(mark[i]>=65 )
        {
           // printf("\nSubject %s\t--> Grade is ",sub[i]);
           // printf("B");
            grd='B';
        }
        else if(mark[i]>=55 )
        {
           // printf("\nSubject %s\t--> Grade is ",sub[i]);
           // printf("C");
            grd='C';
        }
        else if(mark[i]>=35 )
        {
         //   printf("\nSubject %s\t--> Grade is ",sub[i]);
           // printf("S");
            grd='S';
        }
        else
        {
          //  printf("\nSubject %s\t--> Grade is ",sub[i]);
          //  printf("F");
            grd='F';
        }

        setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        printf("+----------------+--------+---------+\n");
        printf("| Subject        | Marks  | Grade   |\n");
        printf("+----------------+--------+---------+\n");
        setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("|%-15s |%-6d  |%-9c| \n",sub[i],mark[i],grd);
        printf("+----------------+--------+---------+\n");
        setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


     fprintf(addMarks,"\n%s \t%d \t%c",sub[i],mark[i],grd);


 }

 check();
}

//for get total marks

void sum(int mark[],int range)
{
    int count=0;
    for(int i=0;i<range;i++)
    {
        count=count+mark[i];
    }

    char filesum[50];


    //creating file in the folder
    sprintf(filesum,"%d/total.txt",grade);

    FILE*sumMarks;
    sumMarks=fopen(filesum,"a");

    fprintf(sumMarks,"%d  %d\n",stdID,count);
    fclose(sumMarks);
}



//for add student co-Activities option
int studentAcc()
{

    studentBots();


    char filename[50],Acc[160],op;
    int x;

    printf("Enter Student index number:");
    scanf("%d",&stdID);

    //creating file in the folder
    sprintf(filename,"%d/%d_Acc.txt",grade,stdID);

    FILE*addStu;
    addStu=fopen(filename,"a");

    if (addStu== NULL)
    {
        printf("error");
    }
    else
    {
         printf("student file creation is success");
    }

    printf("\nEnter Activity:");
    scanf(" %[^\n]",&Acc);

    fprintf(addStu,"Acctivity: %s ",Acc);

    printf("Do you want to add more Acctivities(Y/N): ");
    scanf(" %c",&op);

    op =toupper(op);

    if(op == 'Y')
    {
        system("cls");
       studentAcc();
    }
    else if(op == 'N')
    {
        printf("\n1.Back to main menue "
               "\n2.Exit");
        scanf(" %d",&x);
        if (x==1)
        {
            system("cls");
            menue(log);
        }else
        {
            return 0;
        }


    }
    else
    {
        printf("invalid input!");
        return 0;
    }


}
int hierarchy(int index[],int marks[],int x)
{

    studentBots();


    printf("%d",index[0]);
    int hMarks,hIndex,y;
    for(int i=0;i<x;i++)
    {
        hMarks=marks[0];
        for (int j=0;j<x;j++)
        {
            if(marks[j]>=hMarks)
            {
                hMarks=marks[j];
                hIndex=index[j];
                y=j;
            }
        }
        printf("%d--%d\n",hIndex,hMarks);
        marks[y]=0;


    }
}


int readTot()
{
    int x=0,temp;
    char filesum[50];

    sprintf(filesum,"%d/total.txt",grade);

    FILE*sumMarks;
    sumMarks=fopen(filesum,"r");


    while((fscanf(sumMarks,"%d",&temp))==1)
    {
      x++;
    }
    x=x/2;

    fclose(sumMarks);

    sumMarks=fopen(filesum,"r");

    int index[x],marks[x],i=0;

    while((fscanf(sumMarks,"%d",&index[i]))==1)
          {

              fscanf(sumMarks,"%d",&marks[i]);

              i++;
          }


    fclose(sumMarks);

    hierarchy(index,marks,x);

}
int gradeList()
{


    studentNum();

    studentBots();

     char fileMarks[50],sub[10],grade1;
     int marks;
     int i=0;

     sprintf(fileMarks,"%d/%d_Marks.txt",grade,stdID);

    FILE*addMarks;
    addMarks=fopen(fileMarks,"r");


    setColor( FOREGROUND_RED | FOREGROUND_BLUE);
    printf("+----------------+--------+---------+\n");
    printf("| Subject        | Marks  | Grade   |\n");
    printf("+----------------+--------+---------+\n");
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

     while((fscanf(addMarks,"%s \t %d \t %c",&sub,&marks,&grade1))==3)

     {
         setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
         printf("|%-15s |%-6d  |%-9c| \n",sub,marks,grade1);
         printf("+----------------+--------+---------+\n");
         setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
         i++;

     }



}

//for color maintain

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


// for display login success
void logsucc()
{
    system("cls");

    studentBots();

      setColor(FOREGROUND_GREEN);

    // Print the ASCII art
    printf("\t.------------------.\n");
    printf("\t| login successes!!! |\n");
    printf("\t'------------------'\n");

    // Reset to the default console color
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}


//for login fail
void logfail()
{
    system("cls");

    studentBots();
      setColor(FOREGROUND_RED);

    // Print the ASCII art
    printf("\t.------------------.\n");
    printf("\t| login failed!!! |\n");
    printf("\t'------------------'\n");

    // Reset to the default console color
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


}


int studentBots() {

    system("cls");

     setColor(FOREGROUND_GREEN | FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("  ______    _                  __                 _    \n");
    printf(".' ____ \\  / |_               |  ]               / |_  \n");
    printf("| (___ \\_|`| |-'__   _    .--.| | .---.  _ .--. `| |-'   \n");
    printf(" _.____`.  | | [  | | | / /'`\\' |/ /__\\[ `.-. | | |   \n");
    printf("| \\____) | | |, | \\_/ |,| \\__/  || \\__., | | | | | |,   \n");
    printf(" \\______.' \\__/ '.__.'_/ '.__.;__]'.__.'[___||__]\\__/  \n\n");
     setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    setColor(FOREGROUND_GREEN | FOREGROUND_RED);
    printf("	 ______      ___    _________   ______\n");
    printf("	|_   _ \\   .'   `. |  _   _  |.' ____ \\ \n");
    printf("	 | |_) | /  .-.  \\|_/ | | \\_|| (___ \\_| \n");
    printf("	 |  __'. | |   | |    | |     _.____`. \n");
    printf("	_| |__) |\\  `-'  /   _| |_   | \\____) |  \n");
    printf("	|_______/  `.___.'   |_____|   \\______.'  \n");
     setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

     setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("-------------------------------------------------------------- \n");
    printf("	     (Student Management System)  \n");
    printf("-------------------------------------------------------------- \n\n\n\n");
    setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


    return 0;
}

int check()
{


    char op;
    int x;

    printf("Do you want to do more activities(Y/N): ");
    scanf(" %c",&op);

    op =toupper(op);

    if(op == 'Y')
    {

        menue(log);

    }
    else if(op == 'N')
    {

            return 0;



    }
    else
    {
        printf("invalid input!");
        return 0;
    }

}


int main()
{


    studentBots();


   int log = login();


   int mNum =menue(log);



   switch(mNum)
   {
       case 1:
       {
           newStudent();
           break;
       }
       case 2:
        {
            getMarks();

            break;
        }
       case 3:
        {
            studentAcc();
            break;
        }
       case 4:
        {
            gradeList();



            break;
        }
       case 5:
        {
            readTot();

            break;
        }
       case 0:
        {
            return 0;
            break;
        }
       case 99:
        {
            log = login();
        }
   }

   return 0;


}
