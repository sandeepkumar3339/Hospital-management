#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void man_login();
void lab_login();
void doctor_login();
void cash_login();
void chemist_login();
void man_login();

void end()
{
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n\n\n");
    printf("\t\t\t\t\t         THANK YOU\n");
    getch();
}

void gotoxy(short x,short y)
{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void general_menu()
{
    int n;
    system("cls");
    printf("\t\t\t\t\t      HOSPITAL SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n\n\n");
    printf("1.Reception\n2.Doctor\n3.Cashier\n4.Pharmacists\n5.Management\n6.Lab\n7.Quit\n");
    scanf("%d",&n);
    if (n==1)
    {
        recep_menu();
    }
    else if(n==2)
    {
        doctor_login();
    }
    else if(n==3)
    {
        cash_login();
    }
    else if (n==4)
    {
        chemist_login();
    }
    else if (n==5)
    {
        man_login();
    }
    else if (n==6)
    {
        lab_login();
    }
    else if (n==7)
    {
        end();
    }
}

void open_screen()
{
    printf("\t\t\t\t\t       HOSPITAl SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t HOSPITAL SYSTEM WELCOMES YOU\n\n\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    printf("Press any key...");
    getch();
    system("cls");
    general_menu();
}

int main()
{
    open_screen();
}
