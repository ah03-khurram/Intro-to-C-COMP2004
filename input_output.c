#include <stdio.h>

int main() {
    char my_var[10]; // variable to store the input

    printf("Insert a string\n");
    scanf("%s", my_var); // scanf reading string
    
    printf("you entered: %s\n", my_var);
}