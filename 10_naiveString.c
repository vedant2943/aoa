#include <stdio.h>
#include <string.h>

int main() {
    int n, m,s,i;
    char text[100],pattern[100];
    printf("Enter the size of the text : ");
    scanf("%d", &n);

    text[n+1];
    printf("Enter the text : ");
    scanf(" %[^\n]", text);
    printf("Enter the size of the pattern : ");
    scanf("%d", &m);
    pattern[m+1]; 
    printf("Enter the pattern to match : ");
    scanf(" %[^\n]", pattern); 

    for (s = 0; s <= n - m; s++) {
        for (i = 0; i < m; i++) {
            if (text[s + i] != pattern[i])
                break;
        }
        if (i == m) {
            printf("Match found at index : %d\n", s);
        }
    }
    return 0;
}
