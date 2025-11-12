################################################################################
##
##  YOUR QUILL
##
################################################################################

#   We'll likely add this into core (later)

add_library(yq_luavk SHARED
    LuaTVM.cpp
    command/LuaCommand.cpp
    event/ExecuteEvent.cpp
    event/ExecuteFileEvent.cpp
    event/ExecuteStringEvent.cpp
    event/LuaEvent.cpp
    request/ExecuteFileRequest.cpp
    request/ExecuteStringRequest.cpp
    request/LuaRequest.cpp
    ui/LuaConsoleUI.cpp
    ui/LuaInputBar.cpp
)

target_include_directories(yq_luavk
    PRIVATE 
        ${LUA_INCLUDE_DIR}
)

target_link_libraries(yq_luavk
    PUBLIC
        yq_lua
        yq_tachyon
)

LinkTest(yq_luavk)
