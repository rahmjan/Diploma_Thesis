# RB
## Build
To build use `make` in this folder. It will create file `test`.  

### Parameters
| Name | Default value |
| ------------- | ------------- |
| _RAINBOW16_32_32_32 <br> _RAINBOW256_68_36_36 <br> _RAINBOW256_92_48_48 | _RAINBOW16_32_32_32  |
| _RAINBOW_CLASSIC <br> _RAINBOW_CYCLIC <br> _RAINBOW_CYCLIC_COMPRESSED | _RAINBOW_CLASSIC  |
| MEM_MEASUREMENT | Not set ||

Find file `rainbow_config.h` for more information.  
The parameters need to be in `B_FLAGS="..."`.  

### Example
`make B_FLAGS="-D_RAINBOW_CLASSIC -D_RAINBOW256_68_36_36"`  
