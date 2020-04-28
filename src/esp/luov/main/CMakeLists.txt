idf_component_register(
	SRCS 		test.c chacha.c Column.c F7Field.c F79Field.c F47Field.c F61Field.c LUOV.c LinearAlgebra.c buffer.c prng.c rng.c intermediateValues.c memory_measurement.c
        INCLUDE_DIRS 	.
			~/.espressif/tools/xtensa-esp32-elf/esp-2019r2-8.2.0/xtensa-esp32-elf/xtensa-esp32-elf/include #path to esp32 compiler
			../../esp-idf/components/xtensa/include
			../../esp-idf/components/freertos/include
			../../esp-idf/components/heap/include
			../../XKCP/lib/high/Keccak/FIPS202
	PRIV_REQUIRES	XKCP
	)

if (B_FLAGS)
	string(REPLACE " " ";" B2_FLAGS ${B_FLAGS})
	target_compile_options(${COMPONENT_LIB} PRIVATE ${B2_FLAGS})
endif()
