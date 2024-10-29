#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* hashPass(const char *password){
    int len = strlen(password);
    char *newPassword = malloc(len + 1); 
    if (newPassword == NULL) {
        return NULL;
    }

    for(int i = 0; i < len; i++){
        unsigned int unique = password[i] + 45 ;
        newPassword[i] = unique;
    }
    newPassword[len] = '\0';

    return newPassword;
}

int signup() {
    char username[100], password[100], line[100];
    int count = 0;
    FILE *ptr;
   
    while (1) {    
        printf("Enter Username: ");
        scanf("%99s", username);

        ptr = fopen("pass.csv", "r");
        // Check if the file could be opened
        if (ptr == NULL) {
            printf("Error Opening File\n");
            return 0;
        }

        while (fgets(line, sizeof(line), ptr) != NULL) {
            char *column = strtok(line, ",");
            count = 1;
            if (strcmp(username, column) == 0) {
                count = 0;
                printf("Username Already Taken\n");
                break;
            }
        }
        fclose(ptr);

        if (count != 0) {
            break;
        }
    }

    printf("Enter Password: ");
    scanf("%99s", password);
    char *hashedPassword = hashPass(password);
    // printf("%s",hashedPassword);

    ptr = fopen("pass.csv", "w");
    if (ptr == NULL) {
        printf("Error Opening File\n");
        return 0;
    }
    fprintf(ptr, "%s,%s\n", username, hashedPassword); 
    fclose(ptr);

    return 1;
}

int checkUsername(char *username) {
    FILE *ptr = fopen("pass.csv", "r");
    char line[1024];
    
    if (!ptr) {
        // perror("Error opening file");
        exit(0);
    }

    // printf("Length of username: %zu\n", strlen(username));
    
    while (fgets(line, sizeof(line), ptr) != NULL) {   
      
        char *column = strtok(line, ",");
        // printf("%s\n", column);
        if (strcmp(username, column) == 0) {
            fclose(ptr);
            return 1;
        }
    }

    fclose(ptr);
    return 0;
}

int checkPassword(char *password, char *username){
    char *hashedPass = hashPass(password);
    FILE *ptr = fopen("pass.csv", "r");

    char line[1000], user[100], pass[1000];
    while (fgets(line, sizeof(line), ptr) != NULL) {
        strcpy(user, strtok(line, ","));
        strcpy(pass, strtok(NULL, "\n"));
        if (strcmp(username, user) == 0 && strcmp(hashedPass, pass) == 0) {
            fclose(ptr);
            return 1;
        }
    }
    fclose(ptr);
    return 0;
}

int login(){
    
    char username[100],password[100];
    printf("Enter Username  : ");
    scanf("%99s",&username);
    printf("Enter Password  : ");
    scanf("%99s",&password);
    if (checkUsername(username)){
        if (checkPassword(password,username)){
            printf("Logged in Succesfully \n");

            return 1;
        }
        else
            printf("Invalid Username Or Password \n");
    }else{
    printf("User not exist \n");
    }
    

    return 0;
}
