#include <stdio.h>
#include <string.h>
#include <time.h>

//User structure
struct user {
    char phone[11];
    char ac[10];
    char pin[6];
    float balance;
};

int main(){
    struct user usr;

    //Decorating console
    system("color 3F");
    time_t now;
    time(&now);
    printf("\n\t\t\t\t\t\t%s", ctime(&now));
    printf("Welcome to our ATM interface");
}