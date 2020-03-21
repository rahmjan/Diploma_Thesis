# LUOV
## How to upload to ESP32
`idf.py [parameters] -n -p `*`USB-port`*` build flash monitor`  
When the upload/fleshing starts: hold boot button + press restart button.  
When the monitoring starts: press restart button.

### Parameters
| Name | Default value |
| ------------- | ------------- |
| FIELD_SIZE | 7  |
| OIL_VARS  | 57  |
| VINEGAR_VARS  | 197  |
| HAKENUM  | 128 |
| FIRST_PART_TARGET  | 32  |
| PRNG_CHACHA <br> PRNG_KECCAK  | PRNG_CHACHA |

Find file `parameters.h` for more information.

### Example
`idf.py -n -p /dev/ttyUSB0 build flash monitor`  

`idf.py -DFIELD_SIZE=79 -DOIL_VARS=76 -DVINEGAR_VARS=341 -DSHAKENUM=256 -DFIRST_PART_TARGET=64 -DPRNG_KECCAK=1 -n -p /dev/ttyUSB0 build flash monitor`  
