#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void doctor_menu();
void end();
void general_menu();



void med_priscription()
{
    char pat_id[20];
    int dd,mm,yy;
    char med_name[30];
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int i,n;
    printf("Enter Patient ID:\n");
    scanf("%s",pat_id);
    printf("Enter date:\n");
    printf("Enter day:");
    scanf("%d",&dd);
    printf("Enter month:");
    scanf("%d",&mm);
    printf("Enter year:");
    scanf("%d",&yy);
    printf("Enter number of medicine to be added\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
      {
           FILE *ek;
           ek=fopen("med_pricp.txt","a");
           printf("Enter Medicine name\n");
           scanf("%s",med_name);
           fprintf(ek,"%s %s %d %d %d\n", pat_id, med_name,dd,mm,yy);
           fclose(ek);
      }
      doctor_menu();
}

void lab_priscription()
{
    char pat_id[20];
    int dd,mm,yy;
    char test_name[30];
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    int i,n;
    printf("Enter Patient ID:\n");
    scanf("%s",pat_id);
    printf("Enter date:\n");
    printf("Enter day:");
    scanf("%d",&dd);
    printf("Enter month:");
    scanf("%d",&mm);
    printf("Enter year:");
    scanf("%d",&yy);
    printf("Enter number of tests to be added\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
      {
           FILE *ek;
           ek=fopen("test_pricp.txt","a");
           printf("Enter test name\n");
           scanf("%s",test_name);
           fprintf(ek,"%s %s %d %d %d\n", pat_id, test_name,dd,mm,yy);
           fclose(ek);
      }
      doctor_menu();
}

void doctor_login()
{
    struct doctor
    {
    char First_name[30];
    char Last_name[30];
    char doctor_id[10];
    char Department[30];
    char Password[30];
    int no_pa;
    int fee;
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    FILE *ek;
    ek=fopen("doctor.txt","r");
    int e=0	;
    char Username[15];
    char Passwor[15];
    do
    {
        int num=rand();
        int n;
        printf("\nEnter your Username and Password");
        printf("\nUSERNAME:");
        scanf("%s",Username);
        printf("\nPASSWORD:");
        scanf("%s",Passwor);
        printf("\n\nCAPTCHA\n");
        printf("%d\n",num);
        printf("Enter the captcha:\n");
        scanf("%d",&n);
        while(fscanf(ek,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department, t.doctor_id, &t.no_pa , t.Password,&t.fee)!=EOF)
        {
            if (strcmp(Username,t.doctor_id)==0 && strcmp(Passwor,t.Password)==0 && num==n)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            doctor_menu();
            getch();
            fclose(ek);
            break;
        }
            else{
                continue;
            }
        }
    fclose(ek);
    }while(e<=2);
    if(e>2)
    {
    printf("\nYou have crossed the limit. You cannot login");
    end();
    getch();
    }
}

void doctor_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Medicine\n2.Lab Tests\n3.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        med_priscription();
    }
    else if (n==2)
    {
        lab_priscription();
    }
    else if (n==3)
    {
        general_menu();
    }
}


