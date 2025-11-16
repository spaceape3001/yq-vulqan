################################################################################
##
##  YOUR QUILL
##
################################################################################

#   We'll likely add this into core (later)

add_library(yq_luavk SHARED
    LuaTVM.cpp
    command/LuaCommand.cpp
    event/LuaEvent.cpp
    reply/LuaExecuteReply.cpp
    reply/LuaReply.cpp
    request/LuaExecuteFileRequest.cpp
    request/LuaExecuteStringRequest.cpp
    request/LuaRequest.cpp
    ui/LuaConsole.cpp
    ui/LuaInputBar.cpp
    ui/LuaWindow.cpp
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
