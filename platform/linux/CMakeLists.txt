# 
#  Copyright (C) 2021 mod.io Pty Ltd. <https://mod.io>
#  
#  This file is part of the mod.io SDK.
#  
#  Distributed under the MIT License. (See accompanying file LICENSE or 
#   view online at <https://github.com/modio/modio-sdk/blob/main/LICENSE>)
# 

if(MODIO_PLATFORM STREQUAL "LINUX")

	# This line is required to force the MBedTLS to use the "-fPIC" compiler option
	set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    cmake_policy(SET CMP0077 NEW)
	set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")
	set (MODIO_PLATFORM_LINUX ON INTERNAL "building for linux")
	set (MODIO_MBEDTLS_LINUX_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/mbedtls/library/")

	enable_language(C)
	enable_language(CXX)

	add_subdirectory(linux)
	set(ENABLE_PROGRAMS OFF CACHE BOOL "")
	set(ENABLE_TESTING OFF CACHE BOOL "")

	execute_process(COMMAND make generated_files WORKING_DIRECTORY ${MODIO_ROOT_DIR}/ext/mbedtls)
	add_subdirectory(${MODIO_ROOT_DIR}/ext/mbedtls mbedtls EXCLUDE_FROM_ALL)
	
	if (MODIO_BUILD_TESTS)
		add_subdirectory(tests EXCLUDE_FROM_ALL)
	endif()

	install(
		DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/linux
		DESTINATION ${CMAKE_INSTALL_PREFIX}/header_only
		COMPONENT header_only
	)
	
	install(
		DIRECTORY ${MODIO_ROOT_DIR}/ext/mbedtls/include/
		DESTINATION ${CMAKE_INSTALL_PREFIX}/header_only/ext/
		COMPONENT header_only
		PATTERN "psa" EXCLUDE
		PATTERN ".gitignore" EXCLUDE
	)
	
	install(
		DIRECTORY ${MODIO_ROOT_DIR}/ext/mbedtls/include/
		DESTINATION ${CMAKE_INSTALL_PREFIX}/static/inc/
		COMPONENT static_library
		PATTERN "psa" EXCLUDE
		PATTERN ".gitignore" EXCLUDE
	)

	install(
		DIRECTORY ${MODIO_MBEDTLS_LINUX_BINARY_DIR}
		DESTINATION ${CMAKE_INSTALL_PREFIX}/static/lib/
		COMPONENT static_library
		PATTERN ".cmake" EXCLUDE
		PATTERN "CMakeFiles" EXCLUDE
	)
endif()
