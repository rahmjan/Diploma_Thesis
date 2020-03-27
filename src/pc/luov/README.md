# LUOV
## Build
To build use `make` in this folder. It will create file `test`.  

### Parameters
| Name | Default value | Possible values |
| ------------- | ------------- | ------------- |
| FIELD_SIZE | 7  | 7, 47, 61, 79 |
| OIL_VARS  | 57  ||
| VINEGAR_VARS  | 197  ||
| HAKENUM  | 128 | 128, 256 |
| FIRST_PART_TARGET  | 32  | 32, 64 |
| PRNG_CHACHA <br> PRNG_KECCAK  | PRNG_CHACHA ||
| MESSAGE_RECOVERY | Not set ||

Find file `parameters.h` for more information.  
The parameters need to be in `B_FLAGS="..."`.  

### Example
`make B_FLAGS="-DFIELD_SIZE=79 -DOIL_VARS=76 -DVINEGAR_VARS=341 -DSHAKENUM=256 -DFIRST_PART_TARGET=64 -DPRNG_KECCAK"`  

