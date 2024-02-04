
project(Babel_Client
    VERSION 1.0
    DESCRIPTION "Babel Client"
    LANGUAGES CXX
)



# Définir les sources de l'application
set(SOURCES
        src/main.cpp
        src/NetworkManager.cpp
        src/Cli.cpp
)

# includes/Audio.hpp

# includes/Contacts.hpp

# includes/Call_Journals.hpp

set(HEADERS
        ../common/Message.hpp
        ../common/Client.hpp
        includes/NetworkManager.hpp
        includes/Cli.hpp
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
list(APPEND CLIENT_EXTRA_INCLUDES "includes")
target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_EXTRA_INCLUDES})
target_include_directories(${PROJECT_NAME} PRIVATE ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include)


find_package(Opus CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}  PRIVATE Opus::opus)




add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}
)
