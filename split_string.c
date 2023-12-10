#include <stdio.h>
#include <string.h>

#define MAX_WORDS   100
#define MAX_CHAR    100

void splitStringIntoWords(char* str) {
    char* words[MAX_WORDS];
    char* word;
    int count = 0;

    word = strtok(str, " ");
    while(word != NULL) {
        words[count] = word;
        count++;
        word = strtok(NULL, " ");
    }

    for(int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }
}

int main() 
{
    char str[MAX_CHAR] = "Hello, this is a test string";
    splitStringIntoWords(str);
    return 0;
}
