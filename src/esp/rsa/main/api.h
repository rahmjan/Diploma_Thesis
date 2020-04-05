#ifndef API_H
#define API_H

#include <mbedtls/rsa.h>
#include <mbedtls/sha256.h>

#ifndef KEY_SIZE
    #define KEY_SIZE 2048
#endif

#ifndef EXPONENT
    #define EXPONENT 65537
#endif

#endif 
