#include "common.h"
#include "create_account.c"
#include "login.c"
#include "validations.c"
#include "loan_screen.c"

// variables are decleared in common file
// global variables are in capital letter

int main()
{
    title("O U R BANK");

    int permisson;
    int option;
    switch (opening_screen()) // returning the option choosing from function. 1 --> create 2--> log in
    {
    case 1:
        create_account();
        break;
    case 2:
        permisson = login();

        if(permisson == 0){ // if something is worng
            while (permisson != 1)
            {
                printf("+----------------------------+\n");
                printf("|         MAIN MENU          |\n");
                printf("+----------------------------+\n");
                printf("| 1. Create Account          |\n");
                printf("| 2. Login                   |\n");
                printf("| 3. Exit                    |\n");
                printf("+----------------------------+\n");         
                                
                scanf("%d",&option);
                getchar();
                switch (option)
                {
                case 1:
                    while (getchar() != '\n'); 
                    create_account();
                    break;

                case 2:
                    permisson = login();
                    main_screen();
                    break;

                case 3:
                    return 0;
                }
            }
            
        }
        else if(permisson == 1){
            main_screen();
        }
        
        break; // break for case 2

    case 3:
        return 0;
    
    default:
        printf("\033[1;31m\nYou entered wrong option. The program is closing....\n\033[0m");
        return 0;
    
    }


return 0;
}