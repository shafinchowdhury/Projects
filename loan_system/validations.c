#ifndef VALIDATIONS_C
#define VALIDATIONS_C

#include "common.h"

// variables are decleared in common file
// global variables are in capital letter

void password_validation()
{
    int password_length = strlen(PASSWORD);
    while (1)
    {
        password_length = strlen(PASSWORD);
        if (password_length <= 8) break;

        printf("\033[1;31mPassword exceeds limit! It must be 8 characters or less.\033[0m\n"
               "\033[1;32mTry again: \033[0m");
        scanf("%s",PASSWORD);
    }

    
}

void nid_validation() {
    FILE *nid_file;
    int valid = 0;
    long long int nid_cheaking;
    char pass_cheaking[PASS_SIZE];
    
    nid_file = fopen(NID_FILE, "r");

    while(fscanf(nid_file, "NID --> %lld       PASS --> %s\n", &nid_cheaking, pass_cheaking) == 2){
        if (NID == nid_cheaking){
            valid = 1;
            break;
        }
    }

    fclose(nid_file);

    if (valid == 1){
        while (1){
            printf("\n\033[1;31mThis NID already exists!!\033[0m\n");
            printf("\n\033[1;32mTry again: \033[0m");
            scanf("%lld", &NID);
            while(getchar() != '\n'); 

            valid = 0;
            nid_file = fopen(NID_FILE, "r");

            while(fscanf(nid_file, "NID --> %lld PASS --> %s\n", &nid_cheaking, pass_cheaking) == 2){
                if (NID == nid_cheaking){
                    valid = 1;
                    break;
                }
            }

            fclose(nid_file);

            if (valid == 0) {
                break;
            }
        }
    }
}

int nid_existance(long long int nid) {

    FILE *user_file = fopen("user_details.txt", "r");

    if (user_file == NULL) {
        return -1;
    }

    char line[400];
    char temp_name[NAME_SIZE];
    char temp_email[EMAIL_SIZE];
    long long int temp_NID;

    while (fgets(line, sizeof(line), user_file)) {
        int extracted = sscanf(line, "NID --> %lld Name --> %99[^\t] Email --> %199[^\n]", 
            &temp_NID, temp_name, temp_email);
        if (extracted == 3 && temp_NID == nid) {
            fclose(user_file);
            strcpy(NAME,temp_name);
            strcpy(EMAIL,temp_email);
            NID = temp_NID;
            return 1;  
        }
    }

    fclose(user_file);
    return 0;  
}

int if_exists_before(char file_name[100], int temp_nid)
{
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: Could not open %s in validations.c in if_exists_before function\n", file_name);
        return -1; 
    }

    char line[1000];
    int validity = 0;

    long long int nid;
    float loan, repayment, emi, interest, paid, due;
    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "NID --> %lld ||  LOAN --> %f BDT ||    REPAYMENT --> %f BDT ||   EMI --> %f BDT ||    INTEREST --> %f BDT || PAID --> %f BDT|| DUE --> %f BDT", &nid, &loan, &repayment, &emi, &interest, &paid, &due) == 7){
            if(nid == temp_nid){
                printf("ok\n");
                validity = 1;
                fclose(file);
                return validity;
            }
        }
    }
    fclose(file);
    return validity;
}

#endif