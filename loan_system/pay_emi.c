#ifndef PAY_EMI_C
#define PAY_EMI_C


#include "common.h"
#include "loan_record.c"

void update_due_function(char file_name[100],long long int target_nid, float new_due, float new_paid) {
    FILE *old = fopen(file_name, "r");
    FILE *temp = fopen("temp.txt", "w");

    if ((old == NULL) || (temp == NULL)) {
        printf("Could not open file.\n");
        return;
    }

    char line[1000];
    long long int nid;
    float loan, repayment, emi, interest, paid, due;

    while (fgets(line, sizeof(line), old)) {
        if (sscanf(line, "NID --> %lld || LOAN --> %f BDT || REPAYMENT --> %f BDT || EMI --> %f BDT || INTEREST --> %f BDT || PAID --> %f BDT|| DUE --> %f BDT", &nid, &loan, &repayment, &emi, &interest, &paid, &due) == 7) {

            if (nid == target_nid) {
                fprintf(temp,
                    "NID --> %lld || LOAN --> %.3f BDT || REPAYMENT --> %.3f BDT || EMI --> %.3f BDT || INTEREST --> %.3f BDT || PAID --> %.3f BDT|| DUE --> %.3f BDT\n",
                    nid, loan, repayment, emi, interest, new_paid, new_due);
            } 
            else {
                fputs(line, temp); // Keeping original
            }
        } else {
            fputs(line, temp);
        }
    }

    fclose(old);
    fclose(temp);

    remove(file_name); // deleteing old_file
    rename("temp.txt", file_name); // renameed temp_file
}


void loan_emi(char file_name[100])
{
    long long int temp_nid;
    float temp_due;
    float temp_emi;
    float temp_repayment;
    float temp_paid;
    float temp_loan;
    float temp_interest;

    int valid = 0;
    

    FILE *file = fopen(file_name, "r");

    if(file == NULL){
        printf("Error in pay_emi source file for opning personal_load_records file\n");
        return;
    }


    char line[1000]; // this will hold a single line
    while (fgets(line, sizeof(line), file)){
        if (sscanf(line, "NID --> %lld ||  LOAN --> %f BDT ||    REPAYMENT --> %f BDT ||   EMI --> %f BDT ||    INTEREST --> %f BDT || PAID --> %f BDT|| DUE --> %f BDT", &temp_nid, &temp_loan, &temp_repayment, &temp_emi, &temp_interest, &temp_paid, &temp_due) == 7)
        {  
            if (temp_nid == NID) {
                valid = 1;
                break;
            }
        }
    }


    if(valid == 1){
        float pay_now;
        if(temp_due <= 0){
            printf("You have no more due\n");
            fclose(file);
            delete_old_record(file_name,temp_nid);
            return;
        }

        printf("\033[1;32m\nYour due ammount: %0.3f\033[0m\n",temp_due);
        printf("\033[1;32mEnter pay amount: \033[0m");
        scanf("%f", &pay_now);
        temp_paid += pay_now;
        temp_due -= pay_now;

        if(temp_due <= 0){
            printf("\033[1;36m\nYour payment is completed... We are deleting your previous records and now you are open for other loans.\033[0m\n");
        }
         // this will modify total paid amount (decleared globaly)
        fclose(file);
        update_due_function(file_name,temp_nid, temp_due, temp_paid);
        printf("\033[1;36m \n--> Thanks for using our bank <-- \033[0m\n");

    }
    else{
        printf("\033[1;31m--> You don't have any record of loan till now <--\033[0m\n");
        
        fclose(file);
    }
  
}

#endif