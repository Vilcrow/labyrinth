if(DEFINED ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}/include)
    set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}/lib)
    set(CPPUTEST_LDFLAGS CppUTest CppUTestExt)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()

set(TEST_APP_NAME ${APP_NAME}_utests)
set(TEST_SOURCES
    utests.cpp
    backpack_test.cpp
    battery_test.cpp
    cassette_test.cpp
    commands_test.cpp
    digitallock_test.cpp
    door_test.cpp
    game_test.cpp
    inscription_test.cpp
    key_test.cpp
    keylock_test.cpp
    player_test.cpp
    room_test.cpp
    safe_test.cpp
    sheet_test.cpp
    shelf_test.cpp
    table_test.cpp
    wall_test.cpp
    watch_test.cpp
)

include_directories(${CPPUTEST_INCLUDE_DIRS} ../src/)
link_directories(${CPPUTEST_LIBRARIES})

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_APP_NAME} ${APP_LIB_NAME} ${CPPUTEST_LDFLAGS})

add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)
