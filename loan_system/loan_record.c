#ifndef LOAN_RECORD_C
#define LOAN_RECORD_C

#include "common.h"

// variables are decleared in common file
// global variables are in capital letter

void write_to_record_in_personal_records()
{
    FILE *record_personal_file;
    record_personal_file = fopen("personal_loan_records.txt", "a");

    if(record_personal_file == NULL){
        printf("Erron opeing personal loan record file\n");
        return;
    }

    PAID = 0,0;
    fprintf(record_personal_file, "NID --> %lld ||  LOAN --> %.3f BDT ||    REPAYMENT --> %.3f BDT ||   EMI --> %.3f BDT ||    INTEREST --> %.3f BDT || PAID --> %.3f BDT|| DUE --> %.3f BDT\n",NID,LOAN_AMOUNT,REPAYMENT,EMI,INTEREST,PAID,REPAYMENT-PAID);
    fclose(record_personal_file);
}

void write_to_record_in_home_records()
{
    FILE *record_home_file;
    record_home_file = fopen("home_loan_records.txt", "a");

    if(record_home_file == NULL){
        printf("Erron opeing personal loan record file\n");
    }
    PAID = 0,0;
    fprintf(record_home_file, "NID --> %lld ||  LOAN --> %.3f BDT ||    REPAYMENT --> %.3f BDT ||   EMI --> %.3f BDT ||    INTEREST --> %.3f BDT || PAID --> %.3f BDT|| DUE --> %.3f BDT\n\n",NID,LOAN_AMOUNT,REPAYMENT,EMI,INTEREST,PAID,REPAYMENT-PAID);
    fclose(record_home_file);
}


void delete_old_record(char file_name[100], long long int target_nid)
{
    FILE *old = fopen(file_name , "r");
    FILE *new = fopen("temp.txt" , "w");

    if (old == NULL || new == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char line[1000];
    long long int nid;
    float loan, repayment, emi, interest, paid, due;
    int is_deleted = 0;

    while (fgets(line, sizeof(line), old)) {
        if (sscanf(line, "NID --> %lld ||  LOAN --> %f BDT ||    REPAYMENT --> %f BDT ||   EMI --> %f BDT ||    INTEREST --> %f BDT || PAID --> %f BDT|| DUE --> %f BDT",
                   &nid, &loan, &repayment, &emi, &interest, &paid, &due) == 7) {
            if (nid == target_nid && due <= 0.001) {
                printf("\033[1;32mRecord for NID %lld deleted (payment complete).\033[0m\n", nid);
                is_deleted = 1;
                continue; // skipping targeted nid part
            }
        }

        fputs(line, new); 
    }

    fclose(old);
    fclose(new);

    remove(file_name);
    rename("temp.txt", file_name);

    if(is_deleted == 1){
        printf("\nYour payment is not completed yet\n");
    }
}

#endif