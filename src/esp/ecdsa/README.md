# ECDSA
## How to upload to ESP32
`idf.py [parameters] -n -p `*`USB-port`*` build flash monitor`  
When the upload/flashing starts: hold boot button + press restart button.  
When the monitoring starts: press restart button.

### Parameters
| Name | Default value | Posible values |
| ------------- | ------------- | ------------- |
| EC_CURVE_BITS | 256  | 192, 224, 256, 384, 521 |
| MEM_MEASUREMENT | Not set ||

Find file `api.h` for more information.  
The parameters need to be in `-DB_FLAGS="..."`.

### Example
`idf.py -n -p /dev/ttyUSB0 build flash monitor`  

`idf.py -DB_FLAGS="-DEC_CURVE_BITS=384 -DMEM_MEASUREMENT" -n -p /dev/ttyUSB0 build flash monitor`  
