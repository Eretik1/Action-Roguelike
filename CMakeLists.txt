cmake_minimum_required(VERSION 3.5.0)
project(RogueLike VERSION 0.1.0 LANGUAGES C CXX)

add_executable(RogueLike 
    source/RogueLike.cpp 
    source/Character.cpp 
    source/Player.cpp 
    source/PlayerController.cpp
    source/headers/AllLibs.h
    source/headers/Character.h
    source/headers/Constants.h
    source/headers/Player.h
    source/headers/PlayerController.h
    source/headers/Textures.h
)

set_target_properties(RogueLike PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


target_link_libraries(RogueLike PRIVATE sfml-graphics)
target_link_libraries(RogueLike PRIVATE sfml-window)
target_link_libraries(RogueLike PRIVATE sfml-system)
target_include_directories(RogueLike PRIVATE source/headers)
set(RESOURCES
    ${CMAKE_SOURCE_DIR}/img/backgroung.jpg
    ${CMAKE_SOURCE_DIR}/img/player_t.png 
    ${CMAKE_SOURCE_DIR}/img/mag.png
    ${CMAKE_SOURCE_DIR}/img/floor.png
)
# foreach(Assets ${RESOURCES})
#     add_custom_command(
#         TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         ${Assets}
#         bin
#         $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
#     )
# endforeach()

