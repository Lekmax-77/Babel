project(Babel_Server
    VERSION 1.0
    DESCRIPTION "Babel Server"
    LANGUAGES CXX
)

set(SOURCES
    src/main.cpp
    src/MultiClientServer.cpp
    src/ClientHandler.cpp
)
#includes/Call_Journals.hpp
#includes/Client.hpp
#includes/Contacts.hpp

set(HEADERS
        includes/ClientHandler.hpp
        ../common/Message.hpp
        ../common/Client.hpp
        includes/DatabasesSqlite.hpp
        includes/MultiClientServer.hpp
)   

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


list(APPEND CLIENT_EXTRA_INCLUDES "includes")
target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_EXTRA_INCLUDES})
target_include_directories(${PROJECT_NAME} PRIVATE ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include)

find_package(SQLiteCpp REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SQLiteCpp_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE SQLiteCpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_SOURCE_DIR}
)
