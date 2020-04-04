# RSA
## How to upload to ESP32
`idf.py [parameters] -n -p `*`USB-port`*` build flash monitor`  
When the upload/flashing starts: hold boot button + press restart button.  
When the monitoring starts: press restart button.

### Parameters
| Name | Default value |
| ------------- | ------------- |
| KEY_SIZE | 2048 |
| EXPONENT | 65537 |
| MEM_MEASUREMENT | Not set |

Find file `api.h` for more information.  
The parameters need to be in `-DB_FLAGS="..."`.

### Example
`idf.py -n -p /dev/ttyUSB0 build flash monitor`  

`idf.py -DB_FLAGS="-DKEY_SIZE=1024" -n -p /dev/ttyUSB0 build flash monitor`  

