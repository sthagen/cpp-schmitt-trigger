# add catch
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
endif()

set(tests
    schmitt_trigger.cpp
    schmitt_trigger_inverting.cpp)

add_executable(schmitt_trigger_test test.cpp ${tests})
target_include_directories(schmitt_trigger_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(schmitt_trigger_test PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME test COMMAND schmitt_trigger_test)
