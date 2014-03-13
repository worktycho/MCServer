
cmake_minimum_required (VERSION 2.6)
project (tolua++)

include_directories ("${PROJECT_SOURCE_DIR}/../../src/")
include_directories ("${PROJECT_SOURCE_DIR}/include/")
include_directories ("${PROJECT_SOURCE_DIR}/../")

file(GLOB LIB_SOURCE
    "src/lib/*.c"
)

file(GLOB BIN_SOURCE
    "src/bin/*.c"
)

add_library(tolualib ${LIB_SOURCE})


if(NOT CMAKE_CROSSCOMPILING)
	add_executable(tolua ${BIN_SOURCE})
	
	#m is the standard math librarys
	if(UNIX)
	target_link_libraries(tolua m ${DYNAMIC_LOADER})
	endif()

	target_link_libraries(tolua lua tolualib)
	
	export(TARGETS tolua FILE ${CMAKE_BINARY_DIR}/ImportExecutables.cmake)
else()
	set(IMPORT_EXECUTABLES "IMPORTFILE-NOTFOUND" CACHE FILEPATH "Point it to the export file from a native build")
  	include(${IMPORT_EXECUTABLES})
endif()



