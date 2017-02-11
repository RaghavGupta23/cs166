#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_upper(char* str, char* new);
void char_replace(char* str, char* new, char from, char to);
void codebook_print(int codebook[26][2]);
void codebook_replace(char* ciphertext, char* new, int codebook[26][2]);

int main(int argc, char const *argv[]) {
    char ciphertext[] = "MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVC\nTVWJCZAAXZBCSSCJXBqCJZCQJZCNSPOXBXSBTVWJC\nJZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLH\nJZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX";
    str_upper(ciphertext, ciphertext);
    // printf("Ciphertext\n%s\n\n", ciphertext);

    printf("Frequency Analysis\n");
    int freq[26];
    for (int i = 0; i < 26; ++i) { freq[i] = 0; }
    // Counting
    for (int i = 0; i < strlen(ciphertext); ++i) {
        int c = ciphertext[i];
        if (c >= 65 && c <= 91) {
            freq[c-65] += 1;
        } else {
            // printf("skipping %d\n", c);
        }
    }
    // Results
    for (int i = 0; i < 26; ++i) { printf("%c: %d\n", i+65, freq[i]); }

    // Build codebook
    int codebook[26][2];
    for (int i = 0; i < 26; ++i) {
        codebook[i][0] = i + 65;
        codebook[i][1] = ' ';
    }
    // Hint
    // MXDXB->NEVER
    char * hint_cipher = "MXDXB";
    char * hint_plain = "NEVER";
    for (int i = 0; i < strlen(hint_cipher); ++i) {
        char c = hint_cipher[i];
        codebook[c-65][1] = hint_plain[i];
    }


    // User input
    while (1) {
        char newtext[strlen(ciphertext)];
        strcpy(newtext, ciphertext);
        codebook_replace(ciphertext, newtext, codebook);
        printf("%s\n%s\n", ciphertext, newtext);
        codebook_print(codebook);
        
        char input[5];
        char rep, ch;

        printf("Replace: ");
        fgets(input, sizeof input, stdin);
        rep = (int) input[0];
        for (int i = 0; i < 26; ++i) {
            if ((codebook[i][1] != ' ') && (codebook[i][0] == rep)) {
                printf("%c already replaced with %c, overwriting\n", rep, codebook[i][1]);
            }
        }

        printf("With: ");
        fgets(input, sizeof input, stdin);
        ch = (int) input[0];
        codebook[rep-65][1] = ch;
    }

    printf("Done\n");
    return 0;
}

// Lower case ascii char in str converted in new
void str_upper(char* str, char* new) {
    for (int i = 0; i < strlen(str); ++i) {
        int c = str[i];
        if (c >= 97 && c <= 122) {
            char upper = c ^ ' ';
            char_replace(str, new, c, upper);
        }
    }
}

// Replace from -> to in str, with result in new
void char_replace(char* str, char* new, char from, char to) {
    // printf("%c%d -> %c%d\n", from, from, to, to);
    char c;
    char newstr[strlen(str)];
    strcpy(newstr, str);
    for (int i = 0; i < strlen(str); ++i) {
        c = str[i];
        if (c == from)
            newstr[i] = to;
    }
    strcpy(new, newstr);
    // printf("Stuff\n");
}

void codebook_print(int codebook[26][2]) {
    for (int i = 0; i < 26; ++i)
        printf("%c -> %c\n", codebook[i][0], codebook[i][1]);
}

void codebook_replace(char* ciphertext, char* new, int codebook[26][2]) {
    char newstr[strlen(ciphertext)];
    for (int i = 0; i < strlen(ciphertext); ++i) {
        int c = ciphertext[i];
        if (c >= 65 && c <= 91) {
            newstr[i] = codebook[c-65][1];
        } else {
            newstr[i] = c;
        }
    }
    strcpy(new, newstr);
}
