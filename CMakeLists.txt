cmake_minimum_required(VERSION 3.27)
project(game)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/SDL2)
link_directories(/usr/lib)

find_library(SDL2_LIBRARY SDL2 PATHS /usr/lib)
find_library(SDL2_IMAGE_LIBRARY SDL2_image PATHS /usr/lib)
find_library(SDL2_TTF_LIBRARY SDL2_ttf PATHS /usr/lib)

include_directories(/usr/include/SDL2)

add_executable(game
    main.cpp
    Core/engine.cpp
    Core/object.cpp
    Core/sprite.cpp
    Scenes/StartScene.cpp
    Components/button.cpp
    Scenes/MainGameScene.cpp

)

target_link_libraries(game
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    minizip
    pthread
    dl
)

