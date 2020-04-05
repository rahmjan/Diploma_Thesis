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
    size_t smlen = 0;
    unsigned char *m  = malloc(sizeof(unsigned char[message_size]));
    unsigned char *sm = malloc(sizeof(unsigned char[CRYPTO_BYTES]));
    clock_t cl;
    float genTime = 0.0;
    float signTime = 0.0;
    float verifyTime = 0.0;

    // Initialization
    mbedtls_ecdsa_context ctx;
    mbedtls_ecdsa_init(&ctx);
    srand((unsigned int) time(NULL));

    for (i = 0; i < NUMBER_OF_KEYPAIRS ; i++) {
        printf("Key pair: %d\n", i+1);

        // time key pair generation
        printf("Generation - start\n");
        cl = clock();
        mbedtls_ecdsa_genkey(&ctx, EC_CURVE, coap_prng_impl, NULL);
        cl = clock() - cl;
        genTime += ((float) cl)/CLOCKS_PER_SEC;
        printf("Generation - end\n");

        for (j = 0; j < SIGNATURES_PER_KEYPAIR ; j++) {
            printf("Signature: %d\n", j+1);

            // pick a random message to sign
            for (k = 0; k < message_size; k++) {
                m[k] = (unsigned char)rand();
            }
            
            // time signing algorithm
            printf("Signature - start\n");
            cl = clock();
            mbedtls_ecdsa_write_signature(&ctx, MBEDTLS_MD_SHA256, m, message_size, sm, &smlen, coap_prng_impl, NULL);
            cl = clock() - cl;
            signTime += ((float)cl) / CLOCKS_PER_SEC;
            if(i+j == 0){
                printf("Actual signature length : %d Bytes\n", smlen);
            }
            printf("Signature - end\n");

            // time verification algorithm
            printf("Verification - start\n");
            cl = clock();
            if (mbedtls_ecdsa_read_signature(&ctx, m, message_size, sm, smlen) != 0) {
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
