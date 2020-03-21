idf_component_register(
	SRCS 		XKCP/lib/low/KeccakP-1600/Reference/KeccakP-1600-reference.c
    			XKCP/lib/high/Keccak/KeccakSpongeWidth1600.c
    			XKCP/lib/high/Keccak/FIPS202/KeccakHash.c
        INCLUDE_DIRS 	XKCP/lib/common
    			XKCP/lib/low/KeccakP-1600/Reference
    			XKCP/lib/high/Keccak	
	)

