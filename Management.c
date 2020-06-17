#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void end();
void man_menu();
void general_menu();

void view_earning()
{
     int total=0,dd,mm,yy,d,m,y;
     int lab_pay,med_pay,doc_pay,sum;
     int to_lab=0,to_doc=0,to_med=0;
     system("cls");
     printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
     printf("\t\t\t\t\t  ************************\n\n\n");
     int num;
     printf("1.Date wise report\n2.Total report\n");
     scanf("%d",&num);
     if(num==1)
     {
         FILE *xy;
         xy=fopen("earning.txt","r");
         printf("Enter date:\n");
         printf("Enter day:\n");
         scanf("%d",&d);
         printf("Enter month:\n");
         scanf("%d",&m);
         printf("Enter year:\n");
         scanf("%d",&y);
         while(fscanf(xy,"%d %d %d %d %d %d %d",&doc_pay,&med_pay,&lab_pay,&sum,&dd,&mm,&yy)!=EOF)
         {
             if(d==dd && m==mm && y==yy)
             {
                 total=total+sum;
                 to_doc=to_doc+doc_pay;
                 to_lab=to_lab+lab_pay;
                 to_med=to_med+med_pay;
                 printf("\n\nAMOUNT DETAILS\n");
                 printf("Doctors        :%d\n",to_doc);
                 printf("Medicines      :%d\n",to_med);
                 printf("Lab Tests      :%d\n",to_lab);
                 printf("Total amount   :%d\n",total);
                 getch();
             }
         }
         fclose(xy);
     }
     else if (num==2)
     {
         FILE *xy;
         xy=fopen("earning.txt","r");
         while(fscanf(xy,"%d %d %d %d %d %d %d",&doc_pay,&med_pay,&lab_pay,&sum,&dd,&mm,&yy)!=EOF)
         {
                 total=total+sum;
                 to_doc=to_doc+doc_pay;
                 to_lab=to_lab+lab_pay;
                 to_med=to_med+med_pay;
                 printf("\n\nAMOUNT DETAILS\n");
                 printf("Doctors        :%d\n",to_doc);
                 printf("Medicines      :%d\n",to_med);
                 printf("Lab Tests      :%d\n",to_lab);
                 printf("Total amount   :%d\n",total);
                 getch();
         }
         fclose(xy);

     }
     man_menu();
}

void man_login()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  int e=0	;
    char Username[15];
    char Password[15];
    char original_Username[25]="admin";
    char original_Password[15]="123";

    do
    {
        printf("\nEnter your Username and Password");
        printf("\nUSERNAME:");
        scanf("%s",Username);
        printf("\nPASSWORD:");
        scanf("%s",Password);
        if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            getch();
            man_menu();
            break;
        }
        else
        {
            printf("\nPassword in incorrect,Try Again ");
            e++;
            getch();
        }
    }while(e<=2);
    if(e>2)
    {
    printf("\nYou have crossed the limit. You cannot login");
    getch();
    end();
    }
}

void cashier_delete()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  struct chemist
  {
    char First_name[30];
    char Last_name[30];
    char cash_id[20];
    char Password[30];
  }s;
  printf("ACCOUNT DEACTIVATION OF CASHIER\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("cashier.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter staff ID to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.cash_id,s.Password)!=EOF)
  {
    if(strcmp(rn,s.cash_id)!=0)
    {
      fprintf(temp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.cash_id,s.Password);
    }
    else
    {
      flag=1;
    }
  }
  fclose(fp1);
  fclose(temp1);
  if(flag==1)
  {
    remove("cashier.txt");
    rename("cpy1.txt","cashier.txt");
    printf("Account deactivated");
  }
  else
  {
    printf("Invalid account");
  }
  man_menu();
}

void lab_delete()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  struct lab
  {
    char First_name[30];
    char Last_name[30];
    char lab_id[20];
    char Password[30];
  }s;
  printf("ACCOUNT DEACTIVATION OF Chemist\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("lab.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter staff ID to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.lab_id,s.Password)!=EOF)
  {
    if(strcmp(rn,s.lab_id)!=0)
    {
      fprintf(temp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.lab_id,s.Password);
    }
    else
    {
      flag=1;
    }
  }
  fclose(fp1);
  fclose(temp1);
  if(flag==1)
  {
    remove("lab.txt");
    rename("cpy1.txt","lab.txt");
    printf("Account deactivated");
  }
  else
  {
    printf("Invalid account");
  }
  man_menu();
}

void chemist_delete()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  struct chemist
  {
    char First_name[30];
    char Last_name[30];
    char staff_id[20];
    char Password[30];
  }s;
  printf("ACCOUNT DEACTIVATION OF Chemist\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("chemist.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter staff ID to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.staff_id,s.Password)!=EOF)
  {
    if(strcmp(rn,s.staff_id)!=0)
    {
      fprintf(temp1,"%s %s %s %s \n",s.First_name, s.Last_name,s.staff_id,s.Password);
    }
    else
    {
      flag=1;
    }
  }
  fclose(fp1);
  fclose(temp1);
  if(flag==1)
  {
    remove("chemist.txt");
    rename("cpy1.txt","chemist.txt");
    printf("Account deactivated");
  }
  else
  {
    printf("Invalid account");
  }
  man_menu();
}

void doctor_delete()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
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
  printf("ACCOUNT DEACTIVATION OF DOCTOR\n");
  FILE *fp1,*temp1;
  int flag=0;
  char rn[10];
  fp1=fopen("doctor.txt","r");
  temp1=fopen("cpy1.txt","w");
  printf("\nEnter staff ID to delete : ");
  scanf("%s",rn);
  while(fscanf(fp1,"%s %s %s %s %d %s %d\n",s.First_name, s.Last_name, s.Department, s.doctor_id,&s.no_pa,s.Password,&s.fee)!=EOF)
  {
    if(strcmp(rn,s.doctor_id)!=0)
    {
      fprintf(temp1,"%s %s %s %s %d %s %d\n",s.First_name, s.Last_name, s.Department, s.doctor_id,s.no_pa,s.Password,s.fee);
    }
    else
    {
      flag=1;
    }
  }
  fclose(fp1);
  fclose(temp1);
  if(flag==1)
  {
    remove("doctor.txt");
    rename("cpy1.txt","doctor.txt");
    printf("Account deactivated");
  }
  else
  {
    printf("Invalid account");
  }
  man_menu();
}

void cre_acc_pha()
{
    struct pharmacy
    {
    char First_name[30];
    char Last_name[30];
    char staff_id[20];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("CASHIER ACCOUNT CREATION\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("chemist.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nStaff ID:\n");
    scanf("%s",t.staff_id);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s \n", t.First_name, t.Last_name,t.staff_id, t.Password);
    fclose(fp);
    man_menu();
}

void cre_acc_lab()
{
    struct lab
    {
    char First_name[30];
    char Last_name[30];
    char lab_id[20];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("CASHIER ACCOUNT CREATION\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("lab.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nStaff ID:\n");
    scanf("%s",t.lab_id);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s \n", t.First_name, t.Last_name,t.lab_id, t.Password);
    fclose(fp);
    man_menu();
}

void cre_acc_cash()
{
    struct cashier
    {
    char First_name[30];
    char Last_name[30];
    char cash_id[20];
    char Password[30];
    }t;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("CASHIER ACCOUNT CREATION\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("cashier.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nStaff ID:\n");
    scanf("%s",t.cash_id);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s \n", t.First_name, t.Last_name,t.cash_id, t.Password);
    fclose(fp);
    man_menu();
}

void cre_acc_doc()
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
    printf("DOCTOR ACCOUNT CREATION\n");
    printf("Enter the details\n");
    FILE *fp;
    fp=fopen("doctor.txt","a");
    printf("\nFirst Name:\n");
    t.First_name[0]=toupper(t.First_name[0]);
    scanf("%s",t.First_name);
    printf("\nLast Name:\n");
    scanf("%s",t.Last_name);
    printf("\nDepartment:\n");
    scanf("%s",t.Department);
    t.Department[0]=toupper(t.Department[0]);
    printf("\nEnter user ID:\n");
    scanf("%s",t.doctor_id);
    printf("Enter number of patient to be viewed per day:\n");
    scanf("%d",&t.no_pa);
    printf("Enter consultant fee:\n");
    scanf("%d",&t.fee);
    printf("\nPassword:\n");
    scanf("%s",t.Password);
    fprintf(fp,"%s %s %s %s %d %s %d\n", t.First_name, t.Last_name, t.Department, t.doctor_id, t.no_pa , t.Password,t.fee);
    fclose(fp);
    man_menu();
}

void doctor()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Add account\n2.Delete account\n3.Back\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        cre_acc_doc();
    }
    else if (n==2)
    {
        doctor_delete();
    }
    else if (n==3)
    {
        man_menu();
    }
}

void cash()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Add account\n2.Delete account\n3.Back\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        cre_acc_cash();
    }
    else if (n==2)
    {
        cashier_delete();
    }
    else if (n==3)
    {
        man_menu();
    }
}

void lab_assistant()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Add account\n2.Delete account\n3.Back\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        cre_acc_lab();
    }
    else if (n==2)
    {
        lab_delete();
    }
    else if (n==3)
    {
        man_menu();
    }
}

void chemist()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Add account\n2.Delete account\n3.Back\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        cre_acc_pha();
    }
    else if (n==2)
    {
        chemist_delete();
    }
    else if (n==3)
    {
        man_menu();
    }
}

void man_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t            MENU\n\n");
    printf("1.Doctor\n2.Cashier\n3.Pharmacists\n4.Lab assistant\n5.View income\n6.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        doctor();
    }
    else if (n==2)
    {
        cash();
    }
    else if (n==3)
    {
        chemist();
    }
    else if (n==4)
    {
        lab_assistant();
    }
    else if (n==5)
    {
        view_earning();
    }
    else if (n==6)
    {
        general_menu();
    }
}
