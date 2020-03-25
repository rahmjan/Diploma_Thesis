/// @file utils_prng.c
/// @brief The implementation of PRNG related functions.
///

#include "utils_prng.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int prng_set(prng_t *ctx, const void *prng_seed, unsigned long prng_seedlen)
{
    memset(ctx, 0, sizeof (prng_t));

    hash_msg(ctx->buf, _HASH_LEN , (const unsigned char *)prng_seed, prng_seedlen);

    return 0;
}

int prng_gen(prng_t *ctx, unsigned char *out, unsigned long outlen) {

   while( outlen ) {
      if( _HASH_LEN == ctx->used ) { hash_msg(ctx->buf, _HASH_LEN , ctx->buf, _HASH_LEN); ctx->used = 0; }
      out[0] = ctx->buf[ctx->used];
      out++;
      ctx->used++;
      outlen--;
   }
   return 0;
}

