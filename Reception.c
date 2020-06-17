#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void general_menu();
void recep_menu();
void gotoxy();

void appointment()
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
    FILE *fp, *temp;
    char id[20];
    fp=fopen("doctor.txt","r");
    temp=fopen("copy.txt","w+");
    printf("Enter the doctor's ID  : ");
    scanf("%s",id);
    while(fscanf(fp,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department,t.doctor_id, &t.no_pa , t.Password,&t.fee)!=EOF)
    {
        if(strcmp(t.doctor_id,id)!=0)
        {
            fprintf(temp,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department, t.doctor_id, t.no_pa , t.Password,t.fee);
        }
        else
        {
            if(t.no_pa>0)
            {
                t.no_pa--;
                fprintf(temp,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department, t.doctor_id, t.no_pa , t.Password,t.fee);
            }

            else
            {
                printf("\n1.Reset limit\n2.close\n");
                int num;
                scanf("%d",&num);
                if (num==1)
                {
                    t.no_pa=10;
                    fprintf(temp,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department, t.doctor_id, t.no_pa , t.Password,t.fee);
                }
                else
                {
                    printf("\nAppointment not available\n");
                }
            }
        }
    }
    fclose(fp);
    fclose(temp);
    remove("doctor.txt");
    rename("copy.txt","doctor.txt");
    recep_menu();
}

void patient_account()
{
    struct patient
    {
    char First_name[30];
    char Last_name[30];
    char patient_id[20];
    int amt;
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("PATIENT ACCOUNT CREATION\n");
    printf("Enter the details\n");
    FILE *fp;
    t.amt=0;
    fp=fopen("pat.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nStaff ID:\n");
    scanf("%s",t.patient_id);
    fprintf(fp,"%s %s %s %d \n", t.First_name, t.Last_name,t.patient_id, t.amt);
    fclose(fp);
    recep_menu();
}

void view_doctors()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char First_name[30];
    char Last_name[30];
    char doctor_id[10];
    char Department[30];
    char Password[30];
    int no_pa,fee;
    FILE *fp;
    fp=fopen("doctor.txt","r");
    gotoxy(1,6);
    printf("ID:");
    gotoxy(10,6);
    printf("Name:");
    gotoxy(30,6);
    printf("Department:");
    gotoxy(50,6);
    int r=8;
    while(fscanf(fp,"%s %s %s %s %d %s %d\n", First_name, Last_name, Department,doctor_id, &no_pa , Password,&fee)!=EOF)
    {
        gotoxy(1,r);
        printf("%s",doctor_id);
        gotoxy(10,r);
        printf("%s",First_name);
        gotoxy(30,r);
        printf("%s",Department);
        gotoxy(50,r);
        r++;
    }
    fclose(fp);
    getch();
    recep_menu();
}

void recep_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t            MENU\n\n");
    printf("1.Add Patient\n2.View Doctors List\n3.Book Appointment\n4.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        patient_account();
    }
    else if (n==2)
    {
        view_doctors();
    }
    else if (n==3)
    {
        appointment();
    }
    else if (n==4)
    {
        general_menu();
    }
}
