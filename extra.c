#include <stdio.h>
#include <string.h>

void string_tokenization();
int main(){

string_tokenization();

    return 0;
}

void string_tokenization() {
    char sentence[] = "This is a sample sentence.";
    char *token;
    const char *delimiter = " ";

    printf("Original sentence: '%s'\n", sentence);
    printf("Tokens:\n");

    token = strtok(sentence, delimiter);
    while (token != NULL) {
        printf("- %s\n", token);
        token = strtok(NULL, delimiter);
    }
}