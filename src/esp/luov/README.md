# LUOV
## How to upload to ESP32
`idf.py [parameters] -n -p `*`USB-port`*` build flash monitor`  
When the upload/flashing starts: hold boot button + press restart button.  
When the monitoring starts: press restart button.

### Parameters
| Name | Default value | Possible values |
| ------------- | ------------- ||
| FIELD_SIZE | 7  | 7, 47, 61, 79 |
| OIL_VARS  | 57  ||
| VINEGAR_VARS  | 197  ||
| HAKENUM  | 128 | 128, 256 |
| FIRST_PART_TARGET  | 32  | 32, 64 |
| PRNG_CHACHA <br> PRNG_KECCAK  | PRNG_CHACHA ||
| MESSAGE_RECOVERY | Not set ||

Find file `parameters.h` for more information.

### Example
`idf.py -n -p /dev/ttyUSB0 build flash monitor`  

`idf.py -DB_FLAGS="-DFIELD_SIZE=79 -DOIL_VARS=76 -DVINEGAR_VARS=341 -DSHAKENUM=256 -DFIRST_PART_TARGET=64 -DPRNG_KECCAK" -n -p /dev/ttyUSB0 build flash monitor`  

