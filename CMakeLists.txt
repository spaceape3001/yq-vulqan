################################################################################
##
##  YOUR QUILL
##
################################################################################

cmake_minimum_required(VERSION 3.26.0)

if("${PROJECT_NAME}" STREQUAL "")
    project(YQ_Vulqan VERSION 0.0.0.3 LANGUAGES CXX)
endif()

include(local.cmake OPTIONAL)

if(NOT DEFINED Feature_SDK)
    SET(Feature_SDK ON)
endif()
if(NOT DEFINED Feature_UnitTests)
    SET(Feature_UnitTests ON)
endif()

if(NOT DEFINED Build_GLM)
    SET(Build_GLM ON)
endif()
if(NOT DEFINED Build_SDK)
    SET(Build_SDK ${Feature_SDK})
endif()
if(NOT DEFINED Build_UnitTests)
    SET(Build_UnitTests ${Feature_UnitTests})
endif()

if(NOT YOUR_QUILL_TOOLBOX)
    if((DEFINED TOOLBOX_DIR) AND (EXISTS ${TOOLBOX_DIR}))
        include(${TOOLBOX_DIR}/configure.cmake)
        add_subdirectory(${TOOLBOX_DIR})
    elseif(EXISTS ${CMAKE_CURRENT_LIST_DIR}/yq-toolbox)
        include(yq-toolbox/configure.cmake)
        add_subdirectory(yq-toolbox)
    elseif(EXISTS ${CMAKE_CURRENT_LIST_DIR}/toolbox)
        include(toolbox/configure.cmake)
        add_subdirectory(toolbox)
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

if(${Build_UnitTests})
    enable_testing()
    add_subdirectory(test)
endif()

add_subdirectory(tool)

if(${Build_SDK})
    add_subdirectory(sdk)
endif()
add_subdirectory(plugin)

#   Not in GIT, but a spot to experiement
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/apix)
    add_subdirectory(apix)
endif()
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/testx)
    add_subdirectory(testx)
endif()
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/toolx)
    add_subdirectory(toolx)
endif()
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/exex)
    add_subdirectory(exex)
endif()
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/sdkx)
    add_subdirectory(sdkx)
endif()
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/playx) 
    add_subdirectory(playx)
endif()
