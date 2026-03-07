################################################################################
##
##  YOUR QUILL
##
################################################################################

project(tachyonxg)
add_library(${PROJECT_NAME} SHARED 
    basic/OnCommand.cpp
    basic/OnEvent.cpp
    basic/OnMessage.cpp
    basic/OnPost.cpp
    basic/OnReply.cpp
    basic/OnRequest.cpp
    basic/SendCommand.cpp
    basic/SendEvent.cpp
    basic/SendMessage.cpp
    basic/SendPost.cpp
    basic/SendReply.cpp
    basic/SendRequest.cpp
)
target_link_libraries(${PROJECT_NAME} PUBLIC yq_xgvk)
LinkTest(${PROJECT_NAME})
