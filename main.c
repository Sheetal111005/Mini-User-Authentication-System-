#include "file.c"


int main(){

 
    int x;
    printf("Sign Up  Or Login  \n"
    "Enter 1. Login \n"
    "Enter 2. Sign Up \n");
    scanf("%d",&x);
    
    while (1)
    {
        static int count = 0;
        if(x == 1){
            while (1)
            {
                if(login())
                    break;
                printf("Try Again \n");
                count++;
                if(count  >= 3 ){
                    printf("Do You Want to sign Up ? (y/n) ");
                    char ch;
                    scanf("%1s",&ch);
                    if(ch == 'y'){
                        
                        if(signup()){
                            printf("Sign Up successfull \n Now try to Login \n");
                            login();
                        }
                    }
                }
                
            }
            break;
        }
        else{
            signup();
            printf("Do You Want to Login ? (y/n) \n");
            char ch;
            scanf("%1s",&ch);
            if(ch == 'y'){
                login();
            }else{
                exit(0);
            }
        }

    }
    return 0;
    
}
