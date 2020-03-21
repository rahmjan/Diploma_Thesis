# RB
## How to upload to ESP32
`idf.py [parameters] -n -p `*`USB-port`*` build flash monitor`  
When the upload/fleshing starts: hold boot button + press restart button.  
When the monitoring starts: press restart button.

### Parameters
| Name | Default value |
| ------------- | ------------- |
| _RAINBOW16_32_32_32 <br> _RAINBOW256_68_36_36 <br> _RAINBOW256_92_48_48| _RAINBOW16_32_32_32  |

 

Find file `rainbow_config.h` for more information.

### Example
`idf.py -n -p /dev/ttyUSB0 build flash monitor`  

`idf.py -D_RAINBOW256_68_36_36=1 -n -p /dev/ttyUSB0 build flash monitor`  
