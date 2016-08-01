
set(COMMON_SRC_FILES
	HalBase.cpp
	haldemox.cpp
	stdafx.cpp)

set(COMMON_HEADERS
	HalBase.h
	stdafx.h)

set(GEN9_SRC_FILES
    HalGen9.cpp
	)

set(GEN10_SRC_FILES
    HalGen10.cpp
	)

set(GEN11_SRC_FILES
    HalGen11.cpp
	)	

set(ALL_SRC
    ${COMMON_SRC_FILES}
	${GEN9_SRC_FILES}
	${GEN10_SRC_FILES}
	${GEN11_SRC_FILES}
	)	
	
add_executable(HalSample "${ALL_SRC}")
