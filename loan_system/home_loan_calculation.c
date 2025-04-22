#ifndef HOME_LOAN_CALCULATION_C
#define HOME_LOAN_CALCULATION_C

#include "common.h"
#include "personal_loan_calculation.c"

// variables are decleared in common file
// global variables are in capital letter

void loan_cheack_and_print(int time, float max_loan)
{
    if(LOAN_AMOUNT > max_loan || LOAN_AMOUNT < 0){ // If someone want to take more money than he can take 
        for(int i = 0; i < 3; i++){
            printf("Invalid input. Please enter a positive amount within your limit.\n");
            printf("%d attemps left : ",3-i);
            scanf("%f",&LOAN_AMOUNT);
            if(LOAN_AMOUNT <= max_loan && LOAN_AMOUNT >= 0){
                details_print(time);
                break;
            }
        }

        if(LOAN_AMOUNT > max_loan || LOAN_AMOUNT < 0){
            printf("SORRY !! Try again form start\n");
            return;
        }
        
    }
    else{
        details_print(time);
    }
}

void job_holder_calculation_home()
{
    // cheaking if minimum requirments are fullfilled or not.
    if(MONTHLY_INCOME < 40000 || JOB_EXPRE < 2){
        printf("\n\033[1;31mSorry !! Minimum salary requirment is 40,000 BDT and minimum job exprience 2 years\033[0m\n");
        return; // return if not fulfilled
    }

    // time options
    printf("Choose your return time:\n"
            "1. 10 years\n"
            "2. 15 years\n"
            "3. 20 years\n"
            "4. 25 years\n"
            "choose option: ");


    int option;
    scanf("%d", &option);
    while (getchar() != '\n'); 

    float max_emi = (MONTHLY_INCOME * 0.4); // 40% of income
    float max_loan;

    switch (option)
    {
    case 1:
        max_loan = max_emi * 120;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(10,max_loan);
        break;

    case 2:
        max_loan = max_emi * 180;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(15,max_loan);
        break;

    case 3:
        max_loan = max_emi * 240;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(20,max_loan);
        break;

    case 4:
        max_loan = max_emi * 300;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(25,max_loan);
        break;

    default:
        printf("Wrong option\n");
        break;
    }
}

void buisness_calculation_home()
{
    // cheaking if minimum requirments are fullfilled or not.
    if(MONTHLY_INCOME < 50000 || JOB_EXPRE < 3){
        printf("\n\033[1;31mSorry !! Per month minimum profit requirment is 50,000 BDT and minimum 3 years of business operation\033[0m\n");
        return;
    }


    printf("Choose your return time:\n"
            "1. 10 years\n"
            "2. 15 years\n"
            "3. 20 years\n"
            "4. 25 years\n"
            "choose option: ");


    int option;
    scanf("%d", &option);
    while (getchar() != '\n'); 

    float max_emi = (MONTHLY_INCOME * 0.5);
    float max_loan;

    switch (option)
    {
    case 1:
        max_loan = max_emi * 120;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(10,max_loan);
        break;

    case 2:
        max_loan = max_emi * 180;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(15,max_loan);
        break;

    case 3:
        max_loan = max_emi * 240;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(20,max_loan);
        break;

    case 4:
        max_loan = max_emi * 300;
        printf("You are eligible for upto %0.0f BDT.\nEnter loan ammount: ",max_loan);
        scanf("%f",&LOAN_AMOUNT);
        loan_cheack_and_print(25,max_loan);
        break;
    default:
        printf("Wrong option\n");
        break;
    }
}


#endif