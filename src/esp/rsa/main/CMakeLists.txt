idf_component_register(
	SRCS 		test.c memory_measurement.c
        INCLUDE_DIRS 	.
			~/.espressif/tools/xtensa-esp32-elf/esp-2019r2-8.2.0/xtensa-esp32-elf/xtensa-esp32-elf/include #path to esp32 compiler
			../../esp-idf/components/freertos/include
			../../esp-idf/components/heap/include
			../../esp-idf/components/mbedtls/mbedtls/include
			../../esp-idf/components/coap/libcoap/include/coap2/
	)

if (B_FLAGS)
	string(REPLACE " " ";" B2_FLAGS ${B_FLAGS})
	target_compile_options(${COMPONENT_LIB} PRIVATE ${B2_FLAGS})
endif()
