//CODE
#include <stdio.h>
#include <string.h>

void naiveStringMatch(char text[], char pattern[]) {
    int i,j;
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    for (i = 0; i <= textLen - patternLen; i++) {
         j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf(" %[^\n]", text);

    printf("Enter the pattern to match: ");
    scanf(" %[^\n]", pattern);

    naiveStringMatch(text, pattern);

    return 0;
}


//OUTPUT

//Enter the text: this is a simple example text for testing
//Enter the pattern to match: example
//Pattern found at index 17

