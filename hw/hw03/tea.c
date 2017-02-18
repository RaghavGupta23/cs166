/*
 * Name:  Hansen Wu
 * Class: CS 166-2
 * Date:  2017-02-17
 */

#include <stdint.h>
#include <stdio.h>

/*
 * This function should take in 64-bits of plaintext and a 128 bit key.
 * It should encrypt the text in place.  Note that text[0] is the left 32
 * bits of the plaintext and text[1] is the right 32 bits of plaintext.
 * Also, note that the key is stored in 4 32-bit blocks.
 */
void encrypt(uint32_t* text, uint32_t* key) {
    // This is what we got
    // printf("%02X\n", text[0]);
    // printf("%02X\n", text[1]);
    // printf("%02X\n", key[0]);
    // printf("%02X\n", key[1]);
    // printf("%02X\n", key[2]);
    // printf("%02X\n", key[3]);

    // Do some magic
    // printf("%02LX\n", sum);
    uint32_t delta = 0x9E3779B9;
    // printf("%02LX\n", delta);
    uint32_t sum = 0x0;

    for (int i = 0; i < 32; ++i) {
        sum += delta;
        text[0] += ((text[1] << 4) + key[0]) ^ (text[1] + sum) ^ ((text[1] >> 5) + key[1]);
        text[1] += ((text[0] << 4) + key[2]) ^ (text[0] + sum) ^ ((text[0] >> 5) + key[3]);
    }

    // return text;
    // Encryption in place so nothing to return
}

/*
 * This function should take in 64-bits of ciphertext and a 128 bit key.
 * It should decrypt the text in place.
 */
void decrypt(uint32_t* text, uint32_t* key) {
    // Do some magic
    uint32_t delta = 0x9E3779B9;
    // printf("%02LX\n", delta);
    uint32_t sum = delta << 5;

    for (int i = 0; i < 32; ++i) {
        text[1] -= ((text[0] << 4) + key[2]) ^ (text[0] + sum) ^ ((text[0] >> 5) + key[3]);
        text[0] -= ((text[1] << 4) + key[0]) ^ (text[1] + sum) ^ ((text[1] >> 5) + key[1]);
        sum -= delta;
    }
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
    // Ci = E(Pi ^ Ci-1, K)
    text[0] ^= iv[0];
    text[1] ^= iv[1];
    encrypt(text, key);
    for (int i = 2; i < 10; i += 2) {
        text[i] ^= text[i-2];
        text[i+1] ^= text[i-1];
        encrypt(text + i, key);
    }

    printf("(CBC) ciphertext= ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/
    // Pi = D(Ci, K) ^ Ci-1
    // Should be a way to save only current & prev ciphertext instead of all
    // Previous attempt had persistent bugs though :(
    uint32_t ciphertext[10];
    for (int i = 0; i < 10; ++i)
        ciphertext[i] = text[i];

    decrypt(text, key);
    text[0] ^= iv[0];
    text[1] ^= iv[1];
    for (int i = 2; i < 10; i += 2) {
        decrypt(text + i, key);
     
        text[i] ^= ciphertext[i-2];
        text[i+1] ^= ciphertext[i-1];
    }

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
    // Ci = Pi ^ E(IV - i, K)
    for (int i = 0; i < 10; i += 2) {
        iv[0] = iv_left - i;
        iv[1] = iv_right - (i+1);
        encrypt(iv,  key);
        text[i] ^= iv[0];
        text[i+1] ^= iv[1];
    }

    printf("(CTR) ciphertext= ");
    print_arr(text, 10);

    /*************************** YOUR CODE HERE ***************************************/
    // Pi = Ci ^ E(IV - i, K)
    for (int i = 0; i < 10; i += 2) {
        iv[0] = iv_left - i;
        iv[1] = iv_right - (i+1);
        encrypt(iv,  key);
        text[i] ^= iv[0];
        text[i+1] ^= iv[1];
    }

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

