#include "common.h"

// variables are decleared in common file
// global variables are in capital letter

int login()

{
    title("LOG IN");

    int valid = 0;
    long long int nid_cheaking; // for nid input from user
    char pass_cheaking[PASS_SIZE]; // for password input from user

    printf("\033[1;32mYour NID: \033[0m");
    scanf("%lld", &NID);
    while(getchar() != '\n');

    printf("\n\033[1;32mPassword: \033[0m");
    scanf("%s",PASSWORD);
    // eleminating buffer overflows
    PASSWORD[strcspn(PASSWORD, "\n")] = '\0';

    FILE *nid_file = fopen("nid_pass.txt", "r");

    if(nid_file == NULL){
        printf("Error in login file in opening file\n");
        return -1;
    }

    while (fscanf(nid_file, "NID --> %lld\t\tPASS --> %s\n",&nid_cheaking,pass_cheaking) == 2)
    {
        if(nid_cheaking == NID && (strcmp(pass_cheaking,PASSWORD) == 0)){
            valid = 1;
            break;
        }
    }

    if(valid == 1){
        printf("\n\033[1;33m----> Log in succesfull <----\033[0m\n");
    }
    else{
        printf("\033[1;31m----> NID or password is incorrect <----\033[0m\n");
    }
    fclose(nid_file);
    return valid;
}