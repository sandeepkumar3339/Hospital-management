#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void pay()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");

    int lab_pay=0,med_pay=0,doc_pay=0,sum=0;
    int price,d,m,y,dd,mm,yy;
    char cus[30],pa[30];

    printf("Enter date:\n");
    printf("Enter day:\n");
    scanf("%d",&dd);
    printf("Enter month:\n");
    scanf("%d",&mm);
    printf("Enter year:\n");
    scanf("%d",&yy);
    printf("Enter Patient ID\n");
    scanf("%s",pa);
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");

    FILE *fp,*ek,*tt;
    fp=fopen("med_cost.txt","r");
    while(fscanf(fp,"%s %d %d %d %d\n",cus,&price,&d,&m,&y)!=EOF)
    {
         if(dd==d && mm==m && yy==y && (strcmp(pa,cus)==0))
         {
             med_pay=med_pay+price;
         }
    }
    fclose(fp);

    ek=fopen("test_cost.txt","r");
    while(fscanf(fp,"%s %d %d %d %d\n",cus,&price,&d,&m,&y)!=EOF)
    {
         if(dd==d && mm==m && yy==y && (strcmp(pa,cus)==0))
         {
             lab_pay=lab_pay+price;
         }
    }
    fclose(ek);

    struct doctor
    {
        char First_name[30];
        char Last_name[30];
        char doctor_id[10];
        char Department[30];
        char Password[30];
        int no_pa;
        int fee;
    }s;
    printf("Enter number of doctors consulted\n");
    int num,i;
    char dd_id[10];
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
         tt=fopen("doctor.txt","r");
         printf("Enter the Doctor's ID\n");
         scanf("%s",dd_id);
         while(fscanf(tt,"%s %s %s %s %d %s %d\n",s.First_name, s.Last_name, s.Department, s.doctor_id,&s.no_pa,s.Password,&s.fee)!=EOF)
         {
             if(strcmp(dd_id,s.doctor_id)==0)
             {
                 doc_pay=doc_pay+s.fee;
             }
         }
         fclose(tt);
    }

    sum = med_pay + lab_pay + doc_pay;

    printf("\n\nPAYMENT DETAILS\n");
    printf("Doctor Fee     :%d\n",doc_pay);
    printf("Medicine cost  :%d\n",med_pay);
    printf("Lab Test cost  :%d\n",lab_pay);
    printf("Total pay      :%d\n",sum);

    FILE *xy;
    xy=fopen("earning.txt","w");
    fprintf(xy,"%d %d %d %d %d %d %d",doc_pay,med_pay,lab_pay,sum,dd,mm,yy);
    fclose(xy);
    cash_menu();
}

void cash_login()
{
    struct chemist
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
    ek=fopen("cashier.txt","r");
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
            cash_menu();
            getch();
            break;
        }
            else
            {
                continue;
            }
        }

    }while(e<=2);
    if(e>2)
    {
    printf("\nYou have crossed the limit. You cannot login");
    end();
    getch();
    }
}

void cash_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Entry\n2.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        pay();
    }
    else if (n==2)
    {
        general_menu();
    }
}


