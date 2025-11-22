################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_luavk SHARED

    LuaCommand.cpp
    LuaConsoleUI.cpp
    LuaEvent.cpp
    LuaExecuteReply.cpp
    LuaExecuteFileRequest.cpp
    LuaExecuteStringRequest.cpp
    LuaInputBarUI.cpp
    LuaReply.cpp
    LuaRequest.cpp
    LuaTVM.cpp
    LuaWindowUI.cpp
)

target_link_libraries(yq_luavk
    PUBLIC
        yq_lua
        yq_tachyon
)

vulqan_library(yq_luavk)
LinkTest(yq_luavk)
