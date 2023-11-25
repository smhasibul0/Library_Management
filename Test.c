#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Structures
struct librarian {
    char id[10];
    char name[100];
    char phone[11];
    char pass[8]
}lb;

struct member {
    int id;
    char name[100];
    int semister;
    char section;
    char dept[20];
    int book;
    char pass[8];
}mem;

struct book {
    int code;
    char name[100];
    char author[30];
    char genre[20];
}bk;


// Functions
void header();
void search_book();
void borrow();
void return_book();
void librarianlogin();
void memberlogin();
void superadmin();
void addlibrarian();
void removelibrarian();

//File pointer
FILE *fp;

int main(){

    // Home screen.
    header();

    int choice;
    printf("\n\nWhat are you?\n");
    printf("\t1. Librarian\n");
    printf("\t2. Member\n");
    printf("\t3. Super Admin\n\n");
    printf("Enter your choise :\t");
    scanf("%d", &choice);

    switch (choice){
        case 0:
            exit(0);
            break;

        case 1:
            librarianlogin();
            break;

        case 2:
            memberlogin();
            break;

        case 3:
            superadmin();
            break;

        default:
            printf("Invalid Choice...\n\n");
            break;

    }
}


//Heading decoration
void header(){
    system("cls");
    system("color 3F");
    time_t now;
    time(&now);
    printf("\n\n\t\t\t\t  ==================== *LIBRARY* ===================");
    printf("\n\t\t\t\t\t\t%s\n\n", ctime(&now));
}

void librarianlogin(){
    char filename[50];
    char userpass[8];
    header();
    printf("\n\t\t\t\t----------------- Librarian ------------------\n");
    printf("\nlogin to your account\n\n");
    printf("User ID : \t");
    scanf("%s", filename);
    fp = fopen(strcat(filename,".dat"), "r");
    fread(&lb, sizeof(struct librarian), 1, fp);
    if (fp != NULL)
    {
        printf("Password: \t");
        scanf("%s", userpass);
        if (strcmp(userpass, lb.pass) == 0)
        {
            printf("Login Successfull\n");
            printf("You are now enteracting as '%s'", lb.name);
        } else
        {
            printf("Wrong Password!");
        }
        

    } else
    {
        printf("Wrong ID\n");
    }
    fclose(fp);

}

void memberlogin(){

}

void superadmin(){
    int choice;
    char username[20];
    char password[20];
    char correctUsername[] = "user";
    char correctPassword[] = "password";
    header();
    printf("Welcome to super admin pannel. login to continue... \n");
    printf("Enter username: \t");
    scanf("%s", username);

    printf("Enter password: \t");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
        {
            header();
            printf("What do you want to do?\n");
            printf("\t1. Add Librarian\n");
            printf("\t2. Remove Librarian");
            printf("\n\nEnter your choice :\t");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                addlibrarian();
                break;

            case 2:
                removelibrarian();
                break;

            default:
                break;
            }


        } else
        {
            printf("Wrong Input");
        }
}

void addlibrarian(){

    header();
    char filename[50];
    printf("Enter details:\n");
    printf("\tID :\t");
    scanf("%s", lb.id);
    printf("\tName :\t");
    fflush(stdin);
    gets(lb.name);
    printf("\tPhone Number :\t");
    scanf("%s", lb.phone);
    printf("\tPassword :\t");
    fflush(stdin);
    gets(lb.pass);
    strcpy(filename, lb.id);
    fp = fopen(strcat(filename,".dat"), "w");
    fwrite(&lb, sizeof(struct librarian), 1, fp);
    if (fwrite != 0)
    {
        printf("\n\nSuccessfully added Librarian");
    } else
    {
        printf("\n\nSomething went wrong. Please try again.....");
    }
    fclose(fp);
}

void removelibrarian(){

}

void search_book(){

}

void borrow(){

}

void return_book(){

}
