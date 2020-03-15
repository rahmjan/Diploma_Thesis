idf_component_register(
	SRCS 		lib/low/KeccakP-1600/Reference/KeccakP-1600-reference.c
    			lib/high/Keccak/KeccakSpongeWidth1600.c
    			lib/high/Keccak/FIPS202/KeccakHash.c
        INCLUDE_DIRS 	${CMAKE_CURRENT_LIST_DIR}/lib/common
    			${CMAKE_CURRENT_LIST_DIR}/lib/low/KeccakP-1600/Reference
    			${CMAKE_CURRENT_LIST_DIR}/lib/high/Keccak	
	)

