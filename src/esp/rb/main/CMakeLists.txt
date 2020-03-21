idf_component_register(
	SRCS 		blas_comm.c parallel_matrix_op.c rainbow.c rainbow_keypair.c rainbow_keypair_computation.c rng.c sign.c test.c utils.c utils_hash.c utils_prng.c
        INCLUDE_DIRS 	.
			~/.espressif/tools/xtensa-esp32-elf/esp-2019r2-8.2.0/xtensa-esp32-elf/xtensa-esp32-elf/include #path to esp32 compiler
			~/esp/esp-wolfssl/wolfssl/wolfssl
	PRIV_REQUIRES	wolfssl
	)

#target_compile_options(${COMPONENT_LIB} PUBLIC -Wno-error)
#target_compile_options(${COMPONENT_LIB} PUBLIC -Wno-error=implicit-function-declaration)
target_compile_options(${COMPONENT_LIB} PUBLIC -D"aligned_alloc(x,y)=malloc(y)")
