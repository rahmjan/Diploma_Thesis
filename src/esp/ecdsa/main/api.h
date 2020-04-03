#ifndef API_H
#define API_H

#include <mbedtls/ecdsa.h>

#ifndef EC_CURVE_BITS
    #define EC_CURVE_BITS 256
#endif

#if EC_CURVE_BITS == 192
    #define EC_CURVE MBEDTLS_ECP_DP_SECP192R1
#elif  EC_CURVE_BITS == 224
    #define EC_CURVE MBEDTLS_ECP_DP_SECP224R1
#elif  EC_CURVE_BITS == 256
    #define EC_CURVE MBEDTLS_ECP_DP_SECP256R1
#elif  EC_CURVE_BITS == 384
    #define EC_CURVE MBEDTLS_ECP_DP_SECP384R1
#elif  EC_CURVE_BITS == 521
    #define EC_CURVE MBEDTLS_ECP_DP_SECP521R1
#endif

#define CRYPTO_BYTES ((EC_CURVE_BITS/8*2)+9)

#endif 
