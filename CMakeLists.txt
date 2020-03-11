cmake_minimum_required(VERSION 3.2)

project(cmake_train)

add_executable(cmake_train src/cmake_train.cpp)

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
