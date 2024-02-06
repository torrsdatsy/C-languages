#include<stdio.h>
#include<string.h>

void getNameInput(int count, char *name){
    while (count <= 10)
    {
        printf("%d. Si %s kay Gwapa!\n", count, name);
        count++;
    }
     
}

int main () {
    int count = 1;
    char name[50];
    
    printf("Enter your Name:  ");
    fflush(stdin);
    scanf("%[^\n]%*s", &name);

    getNameInput(count, name);

    printf("EXITING PROGRAM!");
    

    return 0;
}