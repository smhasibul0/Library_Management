#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Functions
void header();


// Structures


int main(){
    header();

}


//Heading decoration
void header(){
    system("cls");
    system("color 3F");
    time_t now;
    time(&now);
    printf("\n\n\t\t\t\t  ==================== *LIBRARY* ===================");
    printf("\n\t\t\t\t\t\t%s", ctime(&now));

}