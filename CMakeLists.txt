cmake_minimum_required(VERSION 3.2)

project(cmake_train)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(cmake_train main.cpp)

set_target_properties(cmake_train PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(cmake_train PRIVATE
        /W4
    )
else ()
    target_compile_options(cmake_train PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS cmake_train RUNTIME DESTINATION bin)
