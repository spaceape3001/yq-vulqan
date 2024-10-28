################################################################################
##
##  YOUR QUILL
##
################################################################################

cmake_minimum_required(VERSION 3.26.0)

if("${PROJECT_NAME}" STREQUAL "")
    project(YourQuill VERSION 0.0.0.3 LANGUAGES CXX)
endif()

include(local.cmake OPTIONAL)

if(NOT YOUR_QUILL_TOOLBOX)
    if((DEFINED TOOLBOX_DIR) AND (EXISTS ${TOOLBOX_DIR}))
        include(${TOOLBOX_DIR}/configure.cmake)
        add_subdirectory(${TOOLBOX_DIR})
    elseif(EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-toolbox)
        include(yq-toolbox/configure.cmake)
        add_subdirectory(yq-toolbox)
    elseif(EXISTS ${CMAKE_CURRENT_LIST_DIR}/toolbox)
        include(toolbox/configure.cmake)
        add_subdirectory(yq-toolbox)
    else()
        message(FATAL_ERROR "Unable to get a toolbox location, which must be as a directory to this project (but do NOT make it a submodule)")
    endif()
endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})

if(NOT YOUR_QUILL_VULQAN)
    SET(YOUR_QUILL_VULQAN ${CMAKE_CURRENT_LIST_DIR})
endif()

set(YQ_TACHYON_DATA_DIR "${CMAKE_CURRENT_LIST_DIR}/data" )

add_subdirectory(3rd)
add_subdirectory(api)
add_subdirectory(test)
add_subdirectory(tool)
add_subdirectory(sdk)
add_subdirectory(plugin)

