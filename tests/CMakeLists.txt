set(TEST_HEADER_LIST
        tests.h
        )

set(TEST_SOURCE_LIST
        main.c
        )

include_directories(${CGREEN_PUBLIC_INCLUDE_DIRS} ${PROJECT_BINARY_DIR})
add_executable(libdc_env_test ${TEST_SOURCE_LIST} ${TEST_HEADER_LIST} ${SOURCE_LIST} ${HEADER_LIST})

target_compile_features(libdc_env_test PRIVATE c_std_17)

target_include_directories(libdc_env_test PRIVATE ../include)
target_include_directories(libdc_env_test PRIVATE /usr/local/include)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_include_directories(libdc_env_test PRIVATE /opt/homebrew/include)
else ()
    target_include_directories(libdc_env_test PRIVATE /usr/include)
endif ()

find_library(LIBCGREEN cgreen REQUIRED)
find_library(LIBDC_ERROR dc_error REQUIRED)

target_link_libraries(libdc_env_test PRIVATE ${LIBCGREEN})
target_link_libraries(libdc_env_test PRIVATE ${LIBDC_ERROR})

add_test(NAME libdc_env_test COMMAND libdc_env_test)

