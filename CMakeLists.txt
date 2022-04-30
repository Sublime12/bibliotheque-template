cmake_minimum_required(VERSION 3.0.0)
project(bibliotheque VERSION 0.1.0)

add_executable(
    ${PROJECT_NAME}
    main.c
)
add_subdirectory(Modules)

target_link_libraries(
    ${PROJECT_NAME}
    modules
    mysqlclient
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
