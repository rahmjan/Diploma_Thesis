#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "memory_measurement.h"
#include "api.h"

#define NUMBER_OF_KEYPAIRS 1     /* Number of keypairs that is generated during test */
#define SIGNATURES_PER_KEYPAIR 10  /* Number of times each keypair is used to sign a random document, and verify the signature */

int coap_prng_impl(void* ex, unsigned char *buf, size_t len)
{
    while ( len-- )
        *buf++ = rand() & 0xFF;
    return 1;
}

int app_main(void)
{
    printf("SECRET - START!\n");
    startMemoryMeasurement();

    int i, j, k;
    int message_size = 1000;
    unsigned char *m  = malloc(sizeof(unsigned char[message_size]));
    unsigned char *hash  = malloc(sizeof(unsigned char[256/8]));
    unsigned char *sm = malloc(sizeof(unsigned char[(KEY_SIZE/8)+1]));
    clock_t cl;
    float genTime = 0.0;
    float signTime = 0.0;
    float verifyTime = 0.0;

    // Initialization
    mbedtls_rsa_context ctx;
    mbedtls_rsa_init(&ctx, MBEDTLS_RSA_PKCS_V15, 0);
    srand((unsigned int) time(NULL));

    for (i = 0; i < NUMBER_OF_KEYPAIRS ; i++) {
        printf("Key pair: %d\n", i+1);

        // time key pair generation
        printf("Generation - start\n");
        cl = clock();
        mbedtls_rsa_gen_key(&ctx, coap_prng_impl, NULL, KEY_SIZE, EXPONENT);
        cl = clock() - cl;
        genTime += ((float) cl)/CLOCKS_PER_SEC;
        printf("Generation - end\n");

        for (j = 0; j < SIGNATURES_PER_KEYPAIR ; j++) {
            printf("Signature: %d\n", j+1);

            // pick a random message to sign
            for (k = 0; k < message_size; k++) {
                m[k] = (unsigned char)rand();
            }

            // hash
            mbedtls_sha256(m, message_size, hash, 0);
            
            // time signing algorithm
            printf("Signature - start\n");
            cl = clock();
            mbedtls_rsa_pkcs1_sign(&ctx, coap_prng_impl, NULL, MBEDTLS_RSA_PRIVATE, MBEDTLS_MD_SHA256, 0, hash, sm);
            cl = clock() - cl;
            signTime += ((float)cl) / CLOCKS_PER_SEC;
            if(i+j == 0){
                printf("Actual signature length : %d Bytes\n", ctx.len);
            }
            printf("Signature - end\n");

            // time verification algorithm
            printf("Verification - start\n");
            cl = clock();
            if (mbedtls_rsa_pkcs1_verify(&ctx, coap_prng_impl, NULL, MBEDTLS_RSA_PUBLIC, MBEDTLS_MD_SHA256, 0, hash, sm) != 0) {
                printf("Verification of signature Failed!\n");
            }
            cl = clock() - cl;
            verifyTime += ((float)cl) / CLOCKS_PER_SEC;
            printf("Verification - end\n");
        }

    }

    printf("\n");
    printf("Key pair generation took %.4f seconds.\n", genTime / NUMBER_OF_KEYPAIRS);
    printf("Signing took %.4f seconds.\n", (signTime/NUMBER_OF_KEYPAIRS)/SIGNATURES_PER_KEYPAIR );
    printf("Verifying took %.4f seconds.\n\n", (verifyTime / NUMBER_OF_KEYPAIRS) / SIGNATURES_PER_KEYPAIR );

    printf("Size of the contex: %d B\n\n", sizeof(ctx));

    free(m);
    free(sm);

    endMemoryMeasurement();
    printf("SECRET - END!\n");
    fflush(stdout);
    return 0;
}
