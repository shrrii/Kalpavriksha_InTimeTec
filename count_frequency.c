//question- count frequency of letters in given string
//example- input= aaabbccdddaa, output=aa5b2c2d3
// this is my code that i write in today's meeting question it give correct output for freuency but not give in alphabetical order
// as i used to c++ language(in c++ using map i can easily find the frequency )and so for doing question in c i need more practice to learn syntax, 
//and at the time of meeting i understand the logic but can't write it in time 
#include <stdio.h>
#include <string.h>
void count_letters(char *input) {
    int counts[128] = {0};
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        counts[input[i]]++;
    }
    for (i = 0; input[i] != '\0'; i++) {
        if (counts[input[i]] > 0) {
            printf("%c%d", input[i], counts[input[i]]);
            counts[input[i]] = 0; 
        }
    }
    printf("\n");
}

int main() {
    char input[100]; 
    printf("Enter a string: ");
    scanf("%s", input); 
    printf("Input: %s\nOutput: ", input);
    count_letters(input);
    return 0;
}
