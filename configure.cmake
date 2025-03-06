################################################################################
##
##  YOUR QUILL
##
################################################################################

if(NOT YOUR_QUILL_VULQAN)
    SET(YOUR_QUILL_VULQAN ${CMAKE_CURRENT_LIST_DIR})
endif()

set(YQ_TACHYON_DATA_DIR "${CMAKE_CURRENT_LIST_DIR}/data" )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})
