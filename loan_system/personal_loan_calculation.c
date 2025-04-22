#ifndef PERSONAL_LOAN_CALCULATION_C
#define PERSONAL_LOAN_CALCULATION_C

#include "common.h"
#include "loan_record.c"

// variables are decleared in common file
// global variables are in capital letter

int loan_amount_validity(float loan_amount, float loan_limit)
{
    int validity = 0;
    if(LOAN_AMOUNT > loan_limit){
        int i = 1;
        while (i <= 3)
        {
            if(LOAN_AMOUNT < loan_limit+0.1){
                validity = 1;
                return validity;
            }
            if(i != 3){
                printf("ATTEMP = %d\n",i+1);
            }
            else{
                printf("LAST ATTEMP\n");
            }
            printf("You can not take this ammount of loan !!\n");
            printf("Enter ammount under your limit which is %0.0f BDT: ",loan_limit);
            scanf("%f", &LOAN_AMOUNT);
            i++;
        }
        if(LOAN_AMOUNT > loan_limit){
            printf("TRY AGAIN FORM START\n");
            return validity;
        }
    }
    else{
        validity = 1;
        return validity;
    }
}

double calculate_emi(int time) {

    EMI = (LOAN_AMOUNT * 0.005833) * (pow(1.005833, time)) / (pow(1.005833, time) - 1);

    return EMI;
}

void details_print(int time)
{
    EMI = calculate_emi(time);
    REPAYMENT = EMI * time;
    INTEREST = REPAYMENT - LOAN_AMOUNT;

    printf("\n---> EMI: \033[1;33mBDT %0.3f\033[0m per month\n", EMI);
    printf("---> Total Repayment: \033[1;33mBDT %0.3f\033[0m\n", REPAYMENT);
    printf("---> Total Interest: \033[1;33mBDT %0.3f\033[0m\n", INTEREST);
    
    
    printf("Thanks for choosing our bank\n");
}

void job_holder_calculation_personal()
{
    if(MONTHLY_INCOME < 30000){
        printf("\n\033[1;31mSorry !! You don't fullfill the minimum requirment of monthly income\033[0m\n");
        return;
    }
    else if(MONTHLY_INCOME <= 40000){
        printf("You are eligible for 1-5 lakh BDT.\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,500000.0);
        
        if(validity == 1){
            details_print(36);
            write_to_record_in_personal_records();
        }
    }

    else if(MONTHLY_INCOME <= 60000){
        printf("You are eligible for upto 10 lakh BDT.\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,1000000.0);
        
        if(validity == 1){
            details_print(60);
            write_to_record_in_personal_records();
        }
    }

    else if(MONTHLY_INCOME > 60000){
        printf("You are eligible for upto 20 lakh BDT\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,2000000.0);
        
        if(validity == 1){
            details_print(84);
            write_to_record_in_personal_records();
        }
    }
}

void buisness_calculation_personal()
{
    if(MONTHLY_INCOME < 40000){
        printf("\n\033[1;31mSorry !! You don't fullfill the minimum requirment of monthly income\033[0m\n");
        return;
    }
    else if(MONTHLY_INCOME <= 50000){
        printf("You are eligible for 1-3 lakh BDT.\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,300000.0);
        
        if(validity == 1){
            details_print(24);
            write_to_record_in_personal_records();
        }
    }

    else if(MONTHLY_INCOME <= 60000){
        printf("You are eligible for upto 10 lakh BDT.\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,1000000.0);
        
        if(validity == 1){
            details_print(36);
            write_to_record_in_personal_records();
        }
    }

    else if(MONTHLY_INCOME > 60000){
        printf("You are eligible for upto 20 lakh BDT\nEnter loan ammount: ");
        scanf("%f", &LOAN_AMOUNT);
        int validity = loan_amount_validity(LOAN_AMOUNT,2000000.0);
        
        if(validity == 1){
            details_print(60);
            write_to_record_in_personal_records();
        }
    }
}
    

#endif