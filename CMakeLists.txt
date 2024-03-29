cmake_minimum_required(VERSION 3.7...3.23)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(schmitt_trigger VERSION 2020.12 LANGUAGES C CXX)

option(SCHMITT_TRIGGER_BUILD_EXAMPLES "whether or not to build the examples" ON)
option(SCHMITT_TRIGGER_BUILD_TESTS "whether or not to build the tests" ON)

set(include_dest "include")
set(tool_dest "bin")

# add external libraries (not header-only)
# include(external/external.cmake)

# subdirectories
if (SCHMITT_TRIGGER_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if (SCHMITT_TRIGGER_BUILD_EXAMPLES)
	macro(schmitt_trigger_add_examples EXAMPLENAME)
		add_executable(${EXAMPLENAME} ${ARGN})
		set_target_properties(${EXAMPLENAME} PROPERTIES FOLDER examples)
		set_target_properties(${EXAMPLENAME} PROPERTIES CXX_STANDARD 17)
		target_include_directories(${EXAMPLENAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
		add_test(NAME ${EXAMPLENAME} COMMAND ${EXAMPLENAME})
	endmacro()
    add_subdirectory(examples)
endif()
