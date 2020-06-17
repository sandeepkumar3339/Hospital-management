#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void assess()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    char pat_id[20],cus[20];
    int dd,mm,yy;
    int d,m,y;
    char me_name[30];
    FILE *fp;
    printf("Enter date:\n");
    printf("Enter day:\n");
    scanf("%d",&d);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&y);
    printf("Enter Patient ID\n");
    scanf("%s",cus);
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    fp=fopen("test_pricp.txt","r");
    gotoxy(100,6);
    printf("ID      ");
    gotoxy(120,6);
    printf("Test Name");
    gotoxy(150,6);
    int r=8;
    while(fscanf(fp,"%s %s %d %d %d\n", pat_id, me_name,&dd,&mm,&yy)!=EOF)
    {
        if(dd==d && mm==m && yy==y && (strcmp(pat_id,cus)==0))
        {
            gotoxy(100,r);
            printf("%s      ",pat_id);
            gotoxy(120,r);
            printf("%s  ",me_name);
            gotoxy(150,r);
            r++;
        }
    }
    fclose(fp);


    FILE *ek,*xy;
    gotoxy(1,6);
    printf("Enter number to tests: ");
    int num,i,mp=7;
    int drug;
    char med_name[20];
    int price,med_id;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        ek=fopen("test.txt","r");
        gotoxy(1,mp);
        drug=0;
        printf("Enter Medicine ID: ");
        scanf("%d",&drug);
        while(fscanf(ek,"%d %s %d\n", &med_id, med_name, &price)!=EOF)
        {
            if(drug==med_id)
            {
                xy=fopen("test_cost.txt","a+");
                fprintf(xy,"%s %d %d %d %d\n",cus,price,d,m,y);
                fclose(xy);
            }
        }
        mp++;
        fclose(ek);
    }
    lab_menu();
}

void add_test()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  char lab_name[20];
  int price,lab_id;
  int i,n;
  printf("Enter number of Lab tests to be added\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
      {
           FILE *ek;
           ek=fopen("test.txt","a");
           printf("Enter the Test ID\n");
           scanf("%d",&lab_id);
           printf("Enter Test name\n");
           scanf("%s",lab_name);
           printf("Enter price\n");
           scanf("%d",&price);
           fprintf(ek,"%d %s %d\n", lab_id, lab_name, price);
           fclose(ek);
      }
      lab_menu();
}

void lab_login()
{
    struct lab
    {
    char First_name[30];
    char Last_name[30];
    char staff_id[20];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    FILE *ek;
    ek=fopen("lab.txt","r");
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
        while(fscanf(ek,"%s %s %s %s \n", t.First_name, t.Last_name, t.staff_id, t.Password)!=EOF)
        {
            if (strcmp(Username,t.staff_id)==0 && strcmp(Passwor,t.Password)==0 && num==n)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            lab_menu();
            getch();
            fclose(ek);
            break;
        }
            else
            {
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

void lab_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Test entry\n2.Add new Test\n3.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        assess();
    }
    else if (n==2)
    {
        add_test();
    }
    else if (n==3)
    {
        general_menu();
    }
}

