idf_component_register(
	SRCS 		blas_comm.c parallel_matrix_op.c rainbow.c rainbow_keypair.c rainbow_keypair_computation.c rng.c sign.c test.c utils.c utils_hash.c utils_prng.c malloc.c memory_measurement.c
        INCLUDE_DIRS 	.
			~/.espressif/tools/xtensa-esp32-elf/esp-2019r2-8.2.0/xtensa-esp32-elf/xtensa-esp32-elf/include #path to esp32 compiler
			../../esp-idf/components/xtensa/include
			../../esp-idf/components/freertos/include
			../../esp-idf/components/heap/include
			../../esp-wolfssl/wolfssl/wolfssl
	PRIV_REQUIRES	wolfssl
	)

if (B_FLAGS)
	string(REPLACE " " ";" B2_FLAGS ${B_FLAGS})
	target_compile_options(${COMPONENT_LIB} PRIVATE ${B2_FLAGS})
endif()

list(FIND B2_FLAGS "-DMY_ESP_MALLOC" POSITION)
if (POSITION EQUAL -1)
	target_compile_options(${COMPONENT_LIB} PUBLIC -Daligned_alloc\(x,y\)=malloc\(y\))
else()
	target_compile_options(${COMPONENT_LIB} PUBLIC -Daligned_alloc\(x,y\)=my_ESP_malloc\(y\))
	target_compile_options(${COMPONENT_LIB} PUBLIC -Dmalloc\(y\)=my_ESP_malloc\(y\))
	target_compile_options(${COMPONENT_LIB} PUBLIC -Dfree\(y\)=my_ESP_free\(y\))
endif()
