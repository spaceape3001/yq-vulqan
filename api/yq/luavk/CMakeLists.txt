################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_luavk SHARED

    LuaTVM.cpp
    vm.cpp

    command/LuaCommand.cpp
    command/LuaExecuteFileCommand.cpp

    event/LuaEvent.cpp
    gesture/LuaExecuteFileGesture.cpp

    reply/LuaReply.cpp
    reply/LuaExecuteReply.cpp

    request/LuaRequest.cpp
    request/LuaExecuteFileRequest.cpp
    request/LuaExecuteStringRequest.cpp

    ui/LuaConsoleUI.cpp
    ui/LuaInputBarUI.cpp
    ui/LuaWindowUI.cpp
)

target_link_libraries(yq_luavk
    PUBLIC
        yq_lua
        yq_tachyon
        yq_consolevk
)

vulqan_library(yq_luavk)
LinkTest(yq_luavk)
