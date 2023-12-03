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
    char bookcode[10];
    char bookname[100];
    char pass[8];
}mem;

struct book {
    char code[10];
    char name[100];
    char author[30];
    char genre[20];
    int quantity;
}bk;


// Functions
void header();
void main_menu();
void booklist();
void borrow();
void return_book();
void librarianlogin();
void librarian();
void addlibrarian();
void removelibrarian();
void issuedbooks();
void memberlogin();
void member();
void memberdetails();
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
    printf("\t3. All Books\n");
    printf("\t4. Add Member\n");
    printf("\t5. Books that are Borrowed\n");
    printf("\t6. Remove Member\n");
    printf("\t0. Return to main menu\n");
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
        booklist();
    }
    else if (choice == 4)
    {
        addmember();
    }
    else if (choice == 5)
    {
        issuedbooks();
    }
    else if (choice == 6)
    {
        removemember();
    }
    else if (choice == 0)
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

void addlibrarian(){
    int n;
    header();
    char filename[50];
    printf("\n\n\t\t\t\t\t<== Add Librarian ==>\n\n");
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
        fclose(fp);
        printf("\n\nSomething went wrong.\n\n");
        printf("\t1. Try again\n");
        printf("\t2. Main menu\n");
        printf("\t0. Exit");
        scanf("%d", &n);
        if (n==1)
        {
            addlibrarian();
        }
        else if (n==2)
        {
            superadmin();
        }
        else
        {
            exit(0);
        }   
    }
    fclose(fp);
    printf("\tPress 1 to return to main menu\n");
    printf("\tPress 0 to exit\n");
    scanf("%d", &n);
    if (n==1)
    {
        superadmin();
    }
    else
    {
        exit(0);
    }
}

void removelibrarian(){
    header();
    int n;
    char filename[50];
    printf("Remove Member..\n\n");
    printf("Enter Member ID :\t");
    scanf("%s", filename);

    if (filename[0] == 'l')
    {
        if (remove(strcat(filename, ".dat")) == 0)
        {
            printf("Successfully removed librarian.\n\n");
        } else
        {
            printf("Something went wrong!\n\n");
        }
    } else
    {
        printf("Invalid librarian ID!\n\n");
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

void issuedbooks(){
    int n;
    header();
    printf("\t\t\t\t\t<== Issued Books ==>\n\n");
    printf("%-10s %-30s %-10s %-30s\n\n\n", "Student Id", "Student Name", "Book Code", "Book Name");

    fp = fopen("issue.dat", "rb");
    while (fread(&mem, sizeof(struct member), 1, fp))
    {
        printf("%-10s %-30s %-10s %-30s\n\n", mem.id, mem.name, mem.bookcode, mem.bookname);
    }
    fclose(fp);
    printf("\tPress 1 to return to main menu\n");
    printf("\tPress any key to Exit\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        librarian();
        break;
    default:
        exit(0);
        break;
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
    printf("\t4. My Details\n");
    printf("\t0. return to main menu\n");
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
        memberdetails();
    }
    
    else if (choice == 0)
    {
        main_menu();
    }
}

void memberdetails(){
    header();
    int n;
    printf("My details :\n\n");
    printf("\tName : %s\n", mem.name);
    printf("\tId : %s\n", mem.id);
    printf("\tSemister : %d\n", mem.semister);
    printf("\tSection : %s\n", mem.section);
    printf("\tDepartment : %s\n", mem.dept);
    printf("\tBorrowed Book :\n");
    if (mem.bookcode != "\0")
    {
        fp = fopen("books.dat", "rb");

        while (fread(&bk, sizeof(struct book), 1, fp) == 1)
        {
            if(strcmp(mem.bookcode, bk.code) == 0){
                printf("\t\tBook code : %s\n", bk.code);
                printf("\t\tBook name : %s\n", bk.name);
                printf("\t\tBook Author : %s\n", bk.author);
                break;
            }
        }
        fclose(fp);
    }
    printf("\n\n\tPress 1 to return to main menu\n");
    printf("\tPress any key to Exit\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        member();
        break;
    default:
        exit(0);
        break;
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
    header();
    printf("\t\t\t\t\t<== Book List ==>\n\n");
    printf("%-10s %-30s %-20s %-10s %s\n\n\n", "Book Code", "Book Name", "Author", "Genre", "Quantity");

    fp = fopen("books.dat", "rb");
    while (fread(&bk, sizeof(struct book), 1, fp))
    {
        printf("%-10s %-30s %-20s %-10s %d\n\n", bk.code, bk.name, bk.author, bk.genre, bk.quantity);
    }
    fclose(fp);
}

void borrow(){
    char code[10];
    int f = 0,n;
    header();
    printf("\t\t\t\t\tBorrow Book\n\n");
    printf("Enter book code :\t");
    scanf("%s", code);

    fp = fopen("books.dat", "rb");

    while (fread(&bk, sizeof(struct book), 1, fp) == 1)
    {
        if (strcmp(code, bk.code) == 0)
        {
            if (bk.quantity > 0)
            {
                f = 1;
                printf("Book details :\n\n");
                printf("Book code : %s\n", bk.code);
                printf("Book name : %s\n", bk.name);
                printf("Book Author : %s\n", bk.author);
                printf("Book Quantity : %d\n", bk.quantity);
                strcpy(mem.bookcode, bk.code);
                strcpy(mem.bookname, bk.name);
                break;
            }
            else
            {
                printf("Book not available\n");
                printf("Book details :\n\n");
                printf("Book code : %s\n", bk.code);
                printf("Book name : %s\n", bk.name);
                printf("Book Author : %s\n", bk.author);
                printf("Book Quantity : %d\n", bk.quantity);
                break;
            }
        }        
    }
    if (f==0)
    {
        printf("No book found!\n");
        printf("\t1. Try again\n");
        printf("\t2. Return to main menu\n");
        scanf("%d", &n);
        if (n==1)
        {
            borrow();
        }
        else if (n==2)
        {
            member();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        printf("Book borrowed successfully.\n\n");
        bk.quantity = bk.quantity - 1;
        fp = fopen("issue.dat", "ab");
        fwrite(&mem, sizeof(struct member), 1, fp);
        fclose(fp);
    }
    printf("\tPress 1 to return to main menu\n");
    printf("\tPress any key to Exit\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        member();
        break;
    default:
        exit(0);
        break;
    }    
}

void return_book(){
    header();
    char code[10];
    int n,f=0,x;
    printf("\tBorrowed Book :\n");
    if (mem.bookcode != "\0")
    {
        fp = fopen("books.dat", "rb");

        while (fread(&bk, sizeof(struct book), 1, fp) == 1)
        {
            if(strcmp(mem.bookcode, bk.code) == 0){
                printf("\t\tBook code : %s\n", bk.code);
                printf("\t\tBook name : %s\n", bk.name);
                printf("\t\tBook Author : %s\n", bk.author);
                break;
            }
        }
        fclose(fp);
        printf("Confirm return:\n");
        printf("\t1.Yes\n\t2.No\n");
        scanf("%d", &n);
        if (n==1)
        {
            fp = fopen("books.dat", "rb");

            while (fread(&bk, sizeof(struct book), 1, fp) == 1)
            {
                if(strcmp(mem.bookcode, bk.code) == 0){
                    bk.quantity = bk.quantity + 1;
                    break;
                }
            }
            fclose(fp);
            strcpy(code, mem.bookcode);
            strcpy(mem.bookcode, "\0");
            strcpy(mem.bookname, "\0");

            FILE *ft;

            fp = fopen("issue.dat", "rb");
            ft = fopen("temp.dat", "wb");

            while (fread(&mem, sizeof(struct member), 1, fp) == 1)
            {
                if(strcmp(code, mem.bookcode) == 0){
                    f = 1;
                }
                else
                {
                    fwrite(&mem, sizeof(struct member), 1, ft);
                }
            }

            if (f == 1)
            {
                printf("\n\nBook returned successfully.....\n");
            }
            else
            {
                printf("error!\n");
            }

            fclose(fp);
            fclose(ft);

            remove("issue.dat");
            rename("temp.dat", "issue.dat");

            printf("\nPress 1 to go back to main menu\n");
            printf("press 0 to exit.\n");
            scanf("%d", &x);
            if (x==1)
            {
                member();
            }
            else
            {
                exit(0);
            }
        }
        else
        {
            member();
        }
        
    }
}

void addbook(){
    int n;
    header();
    printf("Add Book.....\n");
    printf("Enter details:\n");
    printf("Book code :\t");
    scanf("%s", bk.code);
    printf("Book Name :\t");
    fflush(stdin);
    gets(bk.name);
    printf("Book Author :\t");
    fflush(stdin);
    gets(bk.author);
    printf("Genre :\t");
    scanf("%s", bk.genre);
    printf("Quantity :\t");
    scanf("%d", &bk.quantity);
    fp = fopen("books.dat", "ab");
    fwrite(&bk, sizeof(struct book), 1, fp);
    if (fwrite != 0)
    {
        printf("\n\nSuccessfully added Book\n\n");
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
        librarian();
        break;
    default:
        exit(0);
        break;
    }
}

void removebook(){
    char code[10];
    int f=0,n;
    header();
    printf("<==== Remove Book ==>\n\n");
    printf("Enter book code to remove book :\t");
    scanf("%s", code);

    FILE *ft;

    fp = fopen("books.dat", "rb");
    ft = fopen("temp.dat", "wb");

    while (fread(&bk, sizeof(struct book), 1, fp) == 1)
    {
        if(strcmp(code, bk.code) == 0){
            f = 1;
            printf("Book details :\n\n");
            printf("Book code : %s\n", bk.code);
            printf("Book name : %s\n", bk.name);
            printf("Book Author : %s\n", bk.author);
        }
        else
        {
            fwrite(&bk, sizeof(struct book), 1, ft);
        }
    }

    if (f == 1)
    {
        printf("\n\nBook deleted successfully.....\n");
    }
    else
    {
        printf("No book found.\n");
    }

    fclose(fp);
    fclose(ft);

    remove("books.dat");
    rename("temp.dat", "books.dat");

    printf("\nPress 1 to go back to main menu\n");
    printf("press 0 to exit.\n");
    scanf("%d", &n);
    if (n==1)
    {
        librarian();
    }
    else
    {
        exit(0);
    }

}

void addmember(){
    header();
    int n;
    char filename[50];
    printf("\t\t\t\t <== Add Member ==>\n\n");
    printf("Enter details:\n");
    printf("\tID :\t");
    scanf("%s", mem.id);
    printf("\tName :\t");
    fflush(stdin);
    gets(mem.name);
    printf("\tSemister :\t");
    scanf("%d", &mem.semister);
    printf("\tSection :\t");
    fflush(stdin);
    gets(mem.section);
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
        printf("\n\nSuccessfully added Member\n\n");
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
        librarian();
        break;
    default:
        exit(0);
        break;
    }
}

void removemember(){
    header();
    int n;
    char filename[50];
    printf("Remove Member..\n\n");
    printf("Enter Member ID :\t");
    scanf("%s", filename);

    if (filename[0] != 'l')
    {
        if (remove(strcat(filename, ".dat")) == 0)
        {
            printf("Successfully removed member.\n\n");
        } else
        {
            printf("Something went wrong!\n\n");
        }
    } else
    {
        printf("Invalid Member ID!\n\n");
    }
    printf("\tPress 1 to return to main menu\n");
    printf("\tPress any key to Exit\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        librarian();
        break;
    default:
        exit(0);
        break;
    }
}