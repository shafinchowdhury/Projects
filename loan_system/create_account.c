#include "common.h"

// variables are decleared in common file
// global variables are in capital letter

void create_account()
{
    title("CREATE ACCOUNT"); // function from common.h

    // Name Input
    printf("\n\033[1;32mPlease enter your full name: \033[0m");
    fgets(NAME, NAME_SIZE, stdin);
    NAME[strcspn(NAME, "\n")] = '\0'; // eleminating any buffer

    // NID Input and validation
    printf("\n\033[1;32mEnter your NID number: \033[0m");
    scanf("%lld", &NID);
    while (getchar() != '\n'); 
    nid_validation(); // function from validation.c

    // Email Input
    printf("\n\033[1;32mYour email: \033[0m");
    fgets(EMAIL, EMAIL_SIZE, stdin);
    EMAIL[strcspn(EMAIL, "\n")] = '\0';  // eleminating any buffer

    // Password Input and validation
    printf("\n\033[1;32mSet password (max 8 characters): \033[0m");
    scanf("%s",PASSWORD); 
    password_validation(); // function from validation.c

    FILE *user_file;
    user_file = fopen(USER_FILE , "a"); // user_file decleared in common.h

    if(user_file == NULL){
        printf("Error in create account function to open file!!\n");
        return;
    }

    fprintf(user_file,"NID --> %lld\t\tName --> %s\t\tEmail --> %s\n",NID,NAME,EMAIL);
    fclose(user_file);

    FILE *nid_file;
    nid_file = fopen(NID_FILE , "a"); // NID_file decleared in common.h
    fprintf(nid_file,"NID --> %lld\t\tPASS --> %s\n",NID,PASSWORD);
    fclose(nid_file);

    printf("\n\033[1;33m----> Your account is created successfully !! <----\033[0m\n");

    printf("\033[1;34m+--------------------------------+\033[0m\n");
    printf("\n\033[1;32m  Do you want to log in now?\n"
            "\n  1. Yes log in.\n"
            "\n  2. Exit\n\033[0m");
    printf("\033[1;34m+--------------------------------+\033[0m\n");
    printf("\033[1;34mChoose option: \033[0m\n");
    

    int option;
    scanf("%d",&option);
    while (getchar() != '\n'); // eleminating any buffer overflow

    if(option == 1){
        int permission = login();
        if(permission == 0){
            while (permission != 1)
            {
                permission = login(); // function from login.c file
            }
            
        }
        else if (permission == 1){
            main_screen(); // function from loan_screen.c file
        }
    }
    else{
        printf("\033[1;36m\n--> THANKS FOR USING OUR BANK <--\n\n\033[0m");
        return;
    }
    
}