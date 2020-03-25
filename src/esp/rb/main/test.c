#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "api.h"
#include "malloc.h"

#define NUMBER_OF_KEYPAIRS 1     /* Number of keypairs that is generated during test */
#define SIGNATURES_PER_KEYPAIR 1  /* Number of times each keypair is used to sign a random document, and verify the signature */

int app_main(void)
{
    printf("SECRET - START!\n");

    int i, j, k;
    int message_size = 1000;
    unsigned long long smlen = 0;
    unsigned char *m  = aligned_alloc(32,sizeof(unsigned char[message_size]));
    unsigned char *m2 = aligned_alloc(32,sizeof(unsigned char[message_size]));
    unsigned char *pk = aligned_alloc(32,sizeof(unsigned char[CRYPTO_PUBLICKEYBYTES]));
    unsigned char *sk = aligned_alloc(32,sizeof(unsigned char[CRYPTO_SECRETKEYBYTES]));
    unsigned char *sm = aligned_alloc(32,sizeof(unsigned char[message_size + CRYPTO_BYTES]));
    clock_t cl;

    // Print key and signature sizes
    printf("Public Key takes %d B\n", CRYPTO_PUBLICKEYBYTES );
    printf("Secret Key takes %d B\n", CRYPTO_SECRETKEYBYTES );
    printf("Signature takes %d B\n\n", CRYPTO_BYTES );

    printf("Public Key takes %.2f kB\n", CRYPTO_PUBLICKEYBYTES / 1024.0);
    printf("Secret Key takes %.2f kB\n", CRYPTO_SECRETKEYBYTES / 1024.0);
    printf("Signature takes %.2f kB\n\n", CRYPTO_BYTES / 1024.0);

    srand((unsigned int) time(NULL));

    float genTime = 0.0;
    float signTime = 0.0;
    float verifyTime = 0.0;

    for (i = 0; i < NUMBER_OF_KEYPAIRS ; i++) {
        printf("Cycle: %d!\n", i);

        // time key pair generation
        cl = clock();
        crypto_sign_keypair(pk, sk);
        cl = clock() - cl;
        genTime += ((float) cl)/CLOCKS_PER_SEC;

        for (j = 0; j < SIGNATURES_PER_KEYPAIR ; j++) {
            printf("SubCycle: %d!\n", j);

            // pick a random message to sign
            for (k = 0; k < message_size; k++) {
                m[k] = (unsigned char)rand();
            }

            // time signing algorithm
            cl = clock();
            crypto_sign(sm, &smlen, m, (unsigned long long) message_size, sk);
            cl = clock() - cl;
            signTime += ((float)cl) / CLOCKS_PER_SEC;
            if(i+j == 0){
                printf("signed message length : %lld Bytes\n", smlen);
            }

            // time verification algorithm
            cl = clock();
            if (crypto_sign_open(m2, &smlen, sm, smlen, pk) != 0) {
                printf("Verification of signature Failed!\n");
            }
            cl = clock() - cl;
            verifyTime += ((float)cl) / CLOCKS_PER_SEC;

            // check if recovered message length is correct
            if (smlen != message_size){
                printf("Wrong message size !\n");
            }
            // check if recovered message is correct
            for(k = 0 ; k<message_size ; k++){
                if(m[k]!=m2[k]){
                    printf("Wrong message !\n");
                    break;
                }
            }
        }

    }

    printf("\n");
    printf("Key pair generation took %.4f seconds.\n", genTime / NUMBER_OF_KEYPAIRS);
    printf("Signing took %.4f seconds.\n", (signTime/NUMBER_OF_KEYPAIRS)/SIGNATURES_PER_KEYPAIR );
    printf("Verifying took %.4f seconds.\n\n", (verifyTime / NUMBER_OF_KEYPAIRS) / SIGNATURES_PER_KEYPAIR );

    my_ESP_free(m);
    my_ESP_free(m2);
    my_ESP_free(pk);
    my_ESP_free(sk);
    my_ESP_free(sm);
    printf("SECRET - END!\n");

    fflush(stdout);
    return 0;
}
