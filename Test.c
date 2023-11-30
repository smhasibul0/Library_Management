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
    char id[10];
    char name[100];
    int semister;
    char section[2];
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
void main_menu();
void booklist();
void borrow();
void return_book();
void librarianlogin();
void librarian();
void memberlogin();
void member();
void superadminlogin();
void superadmin();
void addbook();
void removebook();
void addmember();
void removemember();

//File pointer
FILE *fp;

int main(){
    main_menu();
    return 0;
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

//Main Menu
void main_menu(){
    header();
    int choice;
    printf("\n\nWhat are you?\n");
    printf("\t1. Librarian\n");
    printf("\t2. Member\n");
    printf("\t3. Super Admin\n\n");
    printf("Enter your choise :\t");
    scanf("%d", &choice);

    //Librarian
    if (choice == 1)
    {
        librarianlogin();
    }
    //Member
    else if (choice == 2)
    {
        memberlogin();
    }

    //Super Admin
    else if (choice == 3)
    {
        superadminlogin();
    }
    else
    {
        printf("Invalid Choice...\n\n");
        printf("Press any key to exit....\t");
        getch();
        exit(0);
    }
}

void librarianlogin(){
    int choice,n;
    char filename[50];
    char userpass[8];
    header();
    printf("\n\t\t\t\t----------------- Librarian ------------------\n");
    printf("\nlogin to your account\n\n");
    printf("User ID : \t");
    scanf("%s", filename);
    fp = fopen(strcat(filename,".dat"), "r");
    fread(&lb, sizeof(struct librarian), 1, fp);
    fclose(fp);
    printf("Password: \t");
    scanf("%s", userpass);
    if (fp != NULL && strcmp(userpass, lb.pass) == 0)
    {
        librarian();
    } else
    {
        printf("Wrong info...\n\n");
        printf("\t1.Try Again.\n");
        printf("\t0.Exit..\n\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            librarianlogin();
            break;
        
        default:
            exit(0);
            break;
        }
    }
}

void librarian(){
    int choice;
    header();
    printf("Login Successfull...\n");
    printf("Welcome \t'%s'\n\n\n", lb.name);
    printf("What do you want to do?\n\n");
    printf("\t1. Add Book\n");
    printf("\t2. Remove Book\n");
    printf("\t3. Add Member\n");
    printf("\t4. Remove Member\n");
    printf("\t5. Return to main menu\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        addbook();
    }
    else if (choice == 2)
    {
        removebook();
    }
    else if (choice == 3)
    {
        addmember();
    }
    else if (choice == 4)
    {
        removemember();
    }
    else if (choice == 5)
    {
        main_menu();
    }
    
    else
    {
        printf("Invalid Choice!\n");
        printf("Press any key to Exit.......\t");
        getch();
        exit(0);
    }

}

void memberlogin(){
    int choice,n;
    char filename[50];
    char userpass[8];
    header();
    printf("\n\t\t\t\t----------------- Member ------------------\n");
    printf("\nlogin to your account\n\n");
    printf("Member ID : \t");
    scanf("%s", filename);
    fp = fopen(strcat(filename,".dat"), "r");
    fread(&mem, sizeof(struct member), 1, fp);
    if (fp != NULL)
    {
        printf("Password: \t");
        scanf("%s", userpass);
        if (strcmp(userpass, mem.pass) == 0)
        {
            member();

        } else
        {
            printf("Wrong Password!!!\n\n");
            printf("\t1.Try Again.\n");
            printf("\t0.Exit..");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                memberlogin();
                break;
            
            default:
                exit(0);
                break;
            }
        }


    } else
    {
        printf("Wrong ID\n");
        printf("\t1.Try Again.\n");
        printf("\t0.Exit..");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            memberlogin();
            break;
        
        default:
            exit(0);
            break;
        }
    }
    fclose(fp);
}

void member(){
    int choice;
    header();
    printf("Login Successfull...\n");
    printf("Welcome \t'%s'\n\n\n", mem.name);
    printf("What do you want to do?\n\n");
    printf("\t1. Booklist\n");
    printf("\t2. Borrow Book\n");
    printf("\t3. Return Book\n");
    printf("\t4. return to main menu\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        booklist();
    }
    else if (choice == 2)
    {
        borrow();
    }
    else if (choice == 3)
    {
        return_book();
    }
    else if (choice == 4)
    {
        main_menu();
    }
}

void superadminlogin(){
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
            superadmin();

        } else
        {
            printf("Wrong Input...\n\n");
            printf("Press any key to Exit.......\t");
            getch();
            exit(0);
        }
}

void superadmin(){
    int choice, n;
    header();
    printf("What do you want to do?\n");
    printf("\t1. Add Librarian\n");
    printf("\t2. Remove Librarian\n");
    printf("\t3. Go back to main menu\n\n");
    printf("\n\nEnter your choice :\t");
    scanf("%d", &choice);
    if (choice == 1)
    {
        header();
        char filename[50];
        printf("Add Librarian....\n\n");
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
            printf("\n\nSuccessfully added Librarian\n\n");
        } else
        {
            printf("\n\nSomething went wrong. Please try again.....\n\n");
        }
        fclose(fp);
        printf("\tPress 1 to return to main menu\n");
        printf("\tPress any key to Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            superadmin();
            break;
        default:
            exit(0);
            break;
        }
    }
    
    else if (choice == 2)
    {
        header();
        char filename[50];
        printf("Remove Librarian..\n\n");
        printf("Enter Librarian ID :\t");
        scanf("%s", filename);
        if (filename[0] == 'l')
        {
            if (remove(strcat(filename, ".dat")) == 0)
            {
                printf("Successfully removed member.\n");
            } else
            {
                printf("Something went wrong!\n");
            }
        } else
        {
            printf("Invalid Librarian ID!\n");
        }
        printf("\tPress 1 to return to main menu\n");
        printf("\tPress any key to Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            superadmin();
            break;
        default:
            exit(0);
            break;
        
        }
    }
    else if (choice == 3)
    {
        main_menu();
    }
    else
    {
        printf("Invalid choice.....\n");
        exit(0);
    }
}

void booklist(){

}

void borrow(){

}

void return_book(){

}

void addbook(){

}

void removebook(){

}

void addmember(){
    header();
    char filename[50];
    printf("Enter details:\n");
    printf("\tID :\t");
    scanf("%s", mem.id);
    printf("\tName :\t");
    fflush(stdin);
    gets(mem.name);
    printf("\tSemister :\t");
    scanf("%d", &mem.semister);
    printf("\tSection :\t");
    scanf("%s", mem.section);
    printf("\tDepartment :\t");
    scanf("%s", mem.dept);
    printf("\tPassword :\t");
    fflush(stdin);
    gets(mem.pass);
    strcpy(filename, mem.id);
    fp = fopen(strcat(filename,".dat"), "w");
    fwrite(&mem, sizeof(struct member), 1, fp);
    if (fwrite != 0)
    {
        printf("\n\nSuccessfully added Member");
    } else
    {
        printf("\n\nSomething went wrong. Please try again.....");
    }
    fclose(fp);

}

void removemember(){
    header();
    char filename[50];
    printf("Remove Member..\n\n");
    printf("Enter Member ID :\t");
    scanf("%s", filename);

    if (filename[0] != 'l')
    {
        if (remove(strcat(filename, ".dat")) == 0)
        {
            printf("Successfully removed member.");
        } else
        {
            printf("Something went wrong!");
        }
    } else
    {
        printf("Invalid Member ID!");
    }
}
