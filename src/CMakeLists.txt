set(APP_LIB_SOURCE
    backpack.cpp
    battery.cpp
    cassette.cpp
    commands.cpp
    digitallock.cpp
    game.cpp
    door.cpp
    inscription.cpp
    key.cpp
    keylock.cpp
    labyrinth.cpp
    player.cpp
    room.cpp
    safe.cpp
    sheet.cpp
    shelf.cpp
    table.cpp
    wall.cpp
    watch.cpp
)

add_library(${APP_LIB_NAME} ${APP_LIB_SOURCE})

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${APP_LIB_NAME})
