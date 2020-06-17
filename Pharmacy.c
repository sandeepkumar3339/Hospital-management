#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void sell()
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
    fp=fopen("med_pricp.txt","r");
    gotoxy(100,6);
    printf("ID      ");
    gotoxy(120,6);
    printf("Medicine Name");
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
    printf("Enter number to medicine for sale: ");
    int num,i,mp=7;
    int drug;
    char med_name[20];
    int price,med_id;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        ek=fopen("med.txt","r");
        gotoxy(1,mp);
        drug=0;
        printf("Enter Medicine ID: ");
        scanf("%d",&drug);
        while(fscanf(ek,"%d %s %d\n", &med_id, med_name, &price)!=EOF)
        {
            if(drug==med_id)
            {
                xy=fopen("med_cost.txt","a+");
                fprintf(xy,"%s %d %d %d %d\n",cus,price,d,m,y);
                fclose(xy);
            }
        }
        mp++;
        fclose(ek);
    }
    chemist_menu();
}

void delete_med()
{
    struct med
    {
        int med_id;
        char med_name[100];
        int price;
    }b;
  int medid,flag=0;
  FILE *fp, *temp;
  fp=fopen("med.txt","r");
  temp=fopen("copy.txt","w+");
  printf("Enter Medicine ID for the medicine to be deleted : ");
  scanf("%d",&medid);
  while(fscanf(fp,"%d %s %d\n", &b.med_id, b.med_name, &b.price)!=EOF)
    {
      if(medid!=b.med_id)
      {
        fprintf(temp,"%d %s %d\n", b.med_id, b.med_name, b.price);
      }
      else
      {
        flag=1;
      }
    }
    fclose(fp);
    fclose(temp);
    if(flag==1)
    {
      remove("med.txt");
      rename("copy.txt","med.txt");
      printf("Medicine deleted");
    }
    else
    {
      printf("Medicine not found");
    }
    chemist_menu();
}

void add_med()
{
  system("cls");
  printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
  printf("\t\t\t\t\t  ************************\n\n\n");
  char med_name[20];
  int price,med_id;
  int i,n;
  printf("Enter number of medicine to be added\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
      {
           FILE *ek;
           ek=fopen("med.txt","a");
           printf("Enter the Medicine ID\n");
           scanf("%d",&med_id);
           printf("Enter Medicine name\n");
           scanf("%s",med_name);
           printf("Enter price\n");
           scanf("%d",&price);
           fprintf(ek,"%d %s %d\n", med_id, med_name, price);
           fclose(ek);
      }
      chemist_menu();
}

void chemist_login()
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
    FILE *ek;
    ek=fopen("chemist.txt","r");
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
            chemist_menu();
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

void chemist_menu()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("1.Sell medicine\n2.Add new medicine\n3.Delete medicine\n4.Exit\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        sell();
    }
    else if (n==2)
    {
        add_med();
    }
    else if (n==3)
    {
        delete_med();
    }
    else if (n==4)
    {
        general_menu();
    }
}
