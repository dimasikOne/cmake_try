cmake_minimum_required(VERSION 3.2)

project(cmake_train VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

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

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
