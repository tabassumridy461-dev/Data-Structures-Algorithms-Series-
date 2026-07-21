#include <stdio.h>

int main() {

    char str1[100], str2[100];
    int i, length = 0, vowel = 0;
    int isEqual = 1;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    // Remove newline character
    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }

    // String Length
    while(str1[length] != '\0') {
        length++;
    }

    printf("\nLength = %d\n", length);

    // String Copy
    for(i = 0; i <= length; i++) {
        str2[i] = str1[i];
    }

    printf("Copied String = %s\n", str2);

    // String Reverse
    printf("Reversed String = ");

    for(i = length - 1; i >= 0; i--) {
        printf("%c", str1[i]);
    }

    printf("\n");

    // Vowel Count
    for(i = 0; i < length; i++) {

        char ch = str1[i];

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {

            vowel++;
        }
    }

    printf("Number of Vowels = %d\n", vowel);

    // Compare Original and Copied String
    for(i = 0; i <= length; i++) {

        if(str1[i] != str2[i]) {
            isEqual = 0;
            break;
        }

    }

    if(isEqual)
        printf("Both strings are Equal.\n");
    else
        printf("Strings are Not Equal.\n");

    return 0;
}
