#include<string.h>
#include<stdio.h>

#define SUCCESS 1
#define FAILED 0

// This is practice for tommorows practical exam. 

// S ->cAd
// A ->ab | a

int S(), A();

char *cursor;
char string[64];

int main(){
    puts("Enter the string:\n");
    scanf("%s", string);

    cursor = string;

    if(S() && *cursor == '\0'){
        puts("\n String parsed succesfully");
    }else {
        puts("\nString did not parse successfully.");
    }
    return 0;
}

int S() {
    printf("%-16s S-> cAd\n", cursor);
    if(*cursor == 'c'){
        cursor++;
        if(A()) {
            if(*cursor == 'd') {
                cursor++;
                return SUCCESS;
            }
        }
    }
    return FAILED;
}

int A() {
    printf("%-16s A-> ab | a", cursor);

    if(*cursor == 'a'){
        cursor++;
        if(*cursor == 'b'){
            cursor++;
            return SUCCESS;
        }
        return SUCCESS;
    }
    else 
        return FAILED;
}