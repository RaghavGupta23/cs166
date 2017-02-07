#include <stdint.h>
#include <stdio.h>

/*
 * This function should take in 64-bits of plaintext and a 128 bit key.
 * It should encrypt the text in place.  Note that text[0] is the left 32
 * bits of the plaintext and text[1] is the right 32 bits of plaintext.
 * Also, note that the key is stored in 4 32-bit blocks.
 */
void encrypt(uint32_t* text, uint32_t* key) {
    /* YOUR CODE HERE */
}

/*
 * This function should take in 64-bits of ciphertext and a 128 bit key.
 * It should decrypt the text in place.
 */
void decrypt(uint32_t* text, uint32_t* key) {
    /* YOUR CODE HERE */
}

/*
 * Utility function to print your results
 */
void print_arr (uint32_t* arr, int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%02X ", arr[i]);
    }
    printf("\n");
}

/*
 * This function encrypts several blocks with TEA, using electronic codebook mode (ECB).
 */
void ecb_mode_test() {
    int i;
    uint32_t key[] = {0x7e7a9cb4, 0x89a201f3, 0x14d6fed4, 0xbe21afea};

    uint32_t text[] = { 0x9e4587e3, 0xe49383a2,
                        0xe1432902, 0xbe790210,
                        0xa39ffe11, 0x93333276,
                        0x21247348, 0x85956106,
                        0x169f5ea6, 0xdb8a7137 };

    printf("(ECB) plaintext = ");
    print_arr(text, 10);

    for (i=0; i<10; i+=2) {
        encrypt(text+i, key);
    }

    printf("(ECB) ciphertext= ");
    print_arr(text, 10);

    for (i=0; i<10; i+=2) {
        decrypt(text+i, key);
    }

    printf("(ECB) plaintext = ");
    print_arr(text, 10);
}

/*
 * This function (when you make your changes) should encrypt several blocks using TEA,
 * but in cipher block chaining (CBC) mode.
 *
 * USE THE SAME ENCRYPT AND DECRYPT FUNCTIONS AS ECB MODE
 */
void cbc_mode_test() {
    int i;
    uint32_t key[] = {0x7e7a9cb4, 0x89a201f3, 0x14d6fed4, 0xbe21afea};

    uint32_t text[] = { 0x9e4587e3, 0xe49383a2,
                        0xe1432902, 0xbe790210,
                        0xa39ffe11, 0x93333276,
                        0x21247348, 0x85956106,
                        0x169f5ea6, 0xdb8a7137 };

    /* XOR (the ^ operator in C) these values with the first two blocks of your plaintext */
    uint32_t iv[] = { 0x74f78c88, 0x8d8844a1 };

    printf("(CBC) plaintext = ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/


    printf("(CBC) ciphertext= ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/

    printf("(CBC) plaintext = ");
    print_arr(text, 10);
}

/*
 * This function (when you make your changes) should encrypt several blocks using TEA,
 * but in counter (CTR) mode.
 *
 * USE THE SAME ENCRYPT FUNCTION AS ECB MODE.
 *
 * You will not need a decrypt function
 */
void ctr_mode_test() {
    int i;
    uint32_t key[] = {0x7e7a9cb4, 0x89a201f3, 0x14d6fed4, 0xbe21afea};

    uint32_t text[] = { 0x9e4587e3, 0xe49383a2,
                        0xe1432902, 0xbe790210,
                        0xa39ffe11, 0x93333276,
                        0x21247348, 0x85956106,
                        0x169f5ea6, 0xdb8a7137 };

    uint32_t iv_left = 0x74f78c88;
    uint32_t iv_right = 0x8d8844a1;
    uint32_t iv[2];

    printf("(CTR) plaintext = ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/


    printf("(CTR) ciphertext= ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/

    printf("(CTR) plaintext = ");
    print_arr(text, 10);
}


int main(int argc, const char* argv[]) {
    printf("\nECB mode test\n");
    ecb_mode_test();

    printf("\nCBC mode test\n");
    cbc_mode_test();

    printf("\nCTR mode test\n");
    ctr_mode_test();

    return 0;
}

