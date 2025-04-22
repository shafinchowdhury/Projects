#ifndef LOAN_SCREEN_C
#define LOAN_SCREEN_C

#include "common.h"
#include "personal_loan_calculation.c"
#include "home_loan_calculation.c"
#include "pay_emi.c"
#include "loan_record.c"
#include "validations.c"

// variables are decleared in common file
// global variables are in capital letter

void home_loan();
void personal_loan();


void main_screen()
{
    int option;
    int option2;
    int loan_option;
    int prof_option;
    int validity;
    int validity2;

    printf("\033[1;34m\nOptions: \n"
        ">> 1. PAY EMI\n"
        ">> 2. Take Loan\n"
        "Enter option: \033[0m"); 
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\033[1;34m\nYour loan type: \n"
            ">> 1. Personal loan\n"
            ">> 2. Home loan\n"
            "Enter option: \033[0m");
    
            scanf("%d", &prof_option);
        switch (prof_option)
        {
        case 1:
            loan_emi("personal_loan_records.txt"); // function from pay_emi.c file
            break;
        
        case 2:
            loan_emi("home_loan_records.txt"); // function from pay_emi.c file
            break;
        default:
        printf("\033[1;31mWrong option\033[0m\n");
        break;
        }

        break;
    case 2:
    printf("\033[1;34m\nOptions: \n"
        ">> 1. Personal loan\n"
        ">> 2. Home loan\n"
        "Enter option: \033[0m");
 
        scanf("%d", &loan_option);
        switch (loan_option)
        {
        case 1 :
            validity = if_exists_before("personal_loan_records.txt", NID);

            if(validity == 0){
                personal_loan(); // function from loan_screen.c file
            }
            else{
                printf("\033[1;31mYou allready have personal loan in OUR bank. Please complete your repayment then try to take another loan.\033[0m");
                printf("\n\033[1;36m--> THANK YOU FOR USING OUR BANK <--\033[0m");
            }
            break;
        case 2:
            validity2 = if_exists_before("home_loan_records.txt", NID);
            if (validity2 == 0)
            {
                home_loan(); // function from loan_screen.c
            }
            else
            {
                printf("\033[1;31mYou already have a home loan in OUR bank. Please complete your repayment before taking another loan.\033[0m");
                printf("\n\033[1;36m--> THANK YOU FOR USING OUR BANK <--\033[0m\n");
            }
            break;
        default:
            break;
        }
        
        break;
    
    default:
        printf("\033[1;31m--> Wrong option <---\033[0m\n\n");
        break;
    }
    
}



void home_loan()
{
    int found = nid_existance(NID); // function from validation.c file
    int option;

    if(found != 1){ 
        printf("ERROR\n");
        printf("========== %d\n",found); 
        return; // if nid does not exist
    }

    printf("Hello \033[1;33m%s !!\033[0m Please fillup the from below\n\n",NAME);
    printf("\033[1;36m<<NOTE>> You have to be in 25-70 years old\n\n\033[0m");
    printf("\033[1;32m>> AGE: \033[0m");
    scanf("%d", &AGE);

    if(AGE < 25 || AGE > 70){
        printf("\033[1;31mYou have to be in 25-70 years old !! \033[0m\n");
        return;
    }

    printf("\033[1;34mProfession:\n"
        ">> 1. Job Holder\n"
        ">> 2. Own Business\n\033[0m"); 
    printf(">> Choose option: ");
    scanf("%d", &option);

    if(option == 1){
        printf("\033[1;36m<<NOTE>> Minimum salary requirement is 40,000 BDT and minimum job experience 2 years\n\033[0m");
        printf("\033[1;32m>> Monthly salary: \033[0m");
        scanf("%f", &MONTHLY_INCOME);
        printf("\033[1;32m>> Job exprience: \033[0m");
        scanf("%d", &JOB_EXPRE);
        job_holder_calculation_home();  // function from home_loan_calculation.c file
        printf("\n\033[1;34m+======================================+\033[0m\n");
        printf("\033[1;32m|          LOAN APPROVED!             |\033[0m\n");
        printf("\033[1;34m+--------------------------------------+\033[0m\n");
        write_to_record_in_home_records(); // function from loan_record.c file
    }
    else if(option == 2){
        printf("\033[1;36m<<NOTE>> Per month minimum profit requirement is 50,000 BDT and minimum 3 years of business operation\n\033[0m");
        printf("\033[1;32m>> Monthly profit: \033[0m");
        scanf("%f", &MONTHLY_INCOME);
        printf("\033[1;32m>> Years of buisness operation: \033[0m");
        scanf("%d", &JOB_EXPRE);
        buisness_calculation_home(); // function from home_loan_calculation.c file
        write_to_record_in_home_records(); // function from loan_record.c file       
    }
    else{
        printf("\033[1;31mWrong option !!\033[0m");
        return;
    }
}



void personal_loan() {
    int found = nid_existance(NID); // function from validation.c file
    int option;

    if(found != 1){
        printf("ERROR\n");
        printf("========== %d\n",found);
        return;
    }

    printf("\nHello \033[1;33m%s !!\033[0m Please fill-up the from below\n",NAME);
    printf("\033[1;36m<<NOTE>> You have to be in 21-70 years old\n\n\033[0m");
    printf("\033[1;32m>> AGE: \033[0m");
    scanf("%d", &AGE);
    if(AGE < 21 || AGE > 70){
        printf("\033[1;31mYou have to be in 21-70 years old !! \033[0m\n");
        return;
    }

    printf("\033[1;33mProfession:\n"
            ">> 1. Job Holder\n"
            ">> 2. Own buisness\n\033[0m");
    printf("Choose option: ");
    scanf("%d", &option);

    if(option == 1){
        printf("\033[1;36m<<NOTE>> Minimum salary requirement is 30,000 BDT\n\n\033[0m");
        printf("\033[1;32m>> Monthly salary: \033[0m");
        scanf("%f", &MONTHLY_INCOME);
        job_holder_calculation_personal(MONTHLY_INCOME); // function from personal_loan_calculation.c file
    }
    else if(option == 2){
        printf("\033[1;36m<<NOTE>> Minimum profit requirement is 40,000 BDT\n\033[0m");
        printf("\033[1;32m>> Monthly profit: \033[0m");
        scanf("%f", &MONTHLY_INCOME);
        buisness_calculation_personal(MONTHLY_INCOME); // function from personal_loan_calculation.c file
    }
    else{
        printf("\033[1;31mWrong option !!\033[0m");
        return;
    }
    
} 


#endif