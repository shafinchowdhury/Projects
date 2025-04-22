#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define NAME_SIZE 100
#define EMAIL_SIZE 200
#define PASS_SIZE 9
#define USER_FILE "user_details.txt"
#define NID_FILE "nid_pass.txt"
#define PERSONAL_LOAN_FILE "personal_loan_records.txt"
#define HOME_LOAN_FILE "home_loan_records.txt"




// All global declearations are in capital letter to create difference between local and global variables
char NAME[NAME_SIZE];
long long int NID;
char EMAIL[EMAIL_SIZE];
char PASSWORD[PASS_SIZE];
int AGE;
int JOB_EXPRE;
float MONTHLY_INCOME;
float LOAN_AMOUNT;
double EMI;
float REPAYMENT;
float INTEREST;
float PAID;

// functions:
void title();
int login();
void create_account();
void password_validation();
void nid_validation();
void personal_loan();
int opening_screen();
void main_screen();
int nid_existance(long long int nid);

void title(const char *title)
{
    // begin
    printf("==================== %s =====================\n",title);
    // end
}

int opening_screen()
{
    // begin
    printf("\033[1;34m+--------------------------------+\033[0m\n");
    printf("\033[1;33m|   MENU:                        |\033[0m\n");
    printf("\033[1;32m|   1.Create a New Account       |\n");
    printf("\033[1;32m|   2.Log In to Existing Account |\n");
    printf("\033[1;32m|   3.Exit                       |\033[0m\n");
    printf("\033[1;34m+--------------------------------+\033[0m\n");
    printf("\033[1;32mEnter your option (1-3): \033[0m");

    
    int option;
    scanf("%d", &option);
    while (getchar() != '\n');

    return option;
    //end
}



#endif
