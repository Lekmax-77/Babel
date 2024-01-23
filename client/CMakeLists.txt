
project(Babel_Client
    VERSION 1.0
    DESCRIPTION "Babel Client"
    LANGUAGES CXX
)



# Définir les sources de l'application
set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

list(APPEND CLIENT_EXTRA_INCLUDES "includes")
target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_EXTRA_INCLUDES})

# Définir la version minimale de Qt nécessaire
find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}
)
