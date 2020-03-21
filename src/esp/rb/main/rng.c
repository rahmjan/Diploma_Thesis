//
//  rng.c
//
//  Created by Bassham, Lawrence E (Fed) on 8/29/17.
//  Copyright © 2017 Bassham, Lawrence E (Fed). All rights reserved.
//

#include <string.h>
#include "rng.h"
#include "esp_system.h"

int
randombytes(unsigned char *x, unsigned long long xlen)
{
    esp_fill_random(x, xlen);
    return RNG_SUCCESS;
}

