
#For Test
#set(GEN9  0)
#set(GEN10 1)
#set(GEN11 1)


set(COMMON_SRC_FILES
	HalBase.cpp
	haldemox.cpp
	stdafx.cpp)

set(COMMON_HEADERS
	HalBase.h
	stdafx.h)

#Platform-specific files
if (GEN9)
set(GEN9_SRC_FILES
    HalGen9.cpp
	)
set(PLATFORM_LIST
	${PLATFORM_LIST}
	Gen9)
endif()

if (GEN10)
set(GEN10_SRC_FILES
    HalGen10.cpp
	)
set(PLATFORM_LIST
	${PLATFORM_LIST}
	Gen10)
endif()

if (GEN11)
set(GEN11_SRC_FILES
    HalGen11.cpp
	)
set(PLATFORM_LIST
	${PLATFORM_LIST}
	Gen11)	
endif()

set(ALL_SRC
    ${COMMON_SRC_FILES}
	${GEN9_SRC_FILES}
	${GEN10_SRC_FILES}
	${GEN11_SRC_FILES}
	)	


add_custom_target(
	CustomGenerateHeaders
	COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/HeaderGenerator.py --platform="${PLATFORM_LIST}" --outputfile=${CMAKE_CURRENT_SOURCE_DIR}/HalInit.h
	COMMENT "Generating header file ..."
	DEPENDS HalInit.h
	)


add_executable(HalSample "${ALL_SRC}")

add_dependencies(HalSample CustomGenerateHeaders)


