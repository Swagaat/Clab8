//Solution-1:
#include <stdio.h>

int *biggest_of_two(int *a, int *b) {
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}

int *biggest_of_three(int *a, int *b, int *c) {
    if (*a > *b && *a > *c) {
        return a;
    } else if (*b > *a && *b > *c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int a, b, c;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    int *biggest_two = biggest_of_two(&a, &b);
    int *biggest_three = biggest_of_three(&a, &b, &c);

    printf("The biggest of the two numbers is: %d\n", *biggest_two);
    printf("The biggest of the three numbers is: %d\n", *biggest_three);

    return 0;
}


// Solution-2
#include <stdio.h>

void div_rem(int a, int b, int *quotient, int *remainder) {
    *quotient = a / b;
    *remainder = a % b;
}

int main() {
    int a, b, quotient, remainder;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    div_rem(a, b, &quotient, &remainder);

    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    return 0;
}


// Solution-3
#include <stdio.h>

int string_length(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[100];
    printf("Input a string : ");
    scanf("%s", str);
    
    int length = string_length(str);
    
    printf("The length of the given string %s is:%d", str, length);
    return 0;
}

// Solution-4:
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    printf("Input a string : ");
    scanf("%s", str);

    reverse_string(str);
    printf("Reverse of the string is : %s", str);

    return 0;
}


//SOlution-5:
#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    int i=0, word=0, chr=0;
    printf("\nEnter Your String: ");
    gets(str);
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            word++;
            chr++;
        }
        else
            chr++;
        i++;
    }
    printf("\nNumber of characters: %d", chr);
    printf("\nNumber of words: %d", word+1);
    return 0;
}


// Solution-6:
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Delete white spaces
    int j = 0;
    for (int i = 0; sentence[i]; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            sentence[j++] = sentence[i];
        }
    }
    sentence[j] = '\0';

    // Replace "." with ":"
    for (int i = 0; sentence[i]; i++) {
        if (sentence[i] == '.') {
            sentence[i] = ':';
        }
    }

    printf("Modified sentence: %s", sentence);

    return 0;
}


// Solution-7:
#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];

    printf("Enter string 1: ");
    fgets(string1, 100, stdin);

    printf("Enter string 2: ");
    fgets(string2, 100, stdin);

    // Remove newline characters from input
    string1[strcspn(string1, "\n")] = '\0';
    string2[strcspn(string2, "\n")] = '\0';

    // Concatenate strings
    strcat(string1, string2);

    printf("Concatenated string: %s", string1);

    return 0;
}


// Solution-8:
#include <stdio.h>

void factorial(int n, unsigned long long *result);

int main() {
    int n;
    unsigned long long result;

    printf("Input a number: ");
    scanf("%d", &n);

    factorial(n, &result);

    printf("%d's factorial: %llu", n, result);

    return 0;
}

void factorial(int n, unsigned long long *result) {
    *result = 1;
    for (int i = 1; i <= n; i++) {
        *result *= i;
    }
}


// Solution-9:
#include <stdio.h>

int* multiple_values(int a, int b);

int main() {
    int x = 5, y = 10;
    int *result;

    result = multiple_values(x, y);

    printf("Result 1: %d\n", result[0]);
    printf("Result 2: %d\n", result[1]);

    return 0;
}

int* multiple_values(int a, int b) {
    static int result[2];

    result[0] = a * b;
    result[1] = a + b;

    return result;
}


// Solution-10:
#include <stdio.h>
#include <string.h>

void sort_names(char names[][50], int n);

int main()
{
    char names[10][50];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter the names: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

    sort_names(names, n);

    printf("Sorted names:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}

void sort_names(char names[][50], int n)
{
    char temp[50];
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(strcmp(names[j], names[j+1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
}
