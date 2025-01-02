################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon2) # temporary until switched

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    
    #######################################################
    #   Core First
    
    source/yt/build.cpp
    source/yt/enums.cpp
    source/yt/strings.cpp
    source/yt/Action.cpp
    source/yt/Command.cpp
    source/yt/Delegate.cpp
    source/yt/Post.cpp
    source/yt/Trigger.cpp
    source/yt/Undo.cpp

    #######################################################
    #   Vulqan
    
    #######################################################
    #   Assets (Yes, the above will use some of these)

    source/ya/triggers/AndTrigger.cpp
    source/ya/triggers/KeyPressTrigger.cpp
    source/ya/triggers/NandTrigger.cpp
    source/ya/triggers/NorTrigger.cpp
    source/ya/triggers/NotTrigger.cpp
    source/ya/triggers/OrTrigger.cpp
    source/ya/triggers/PostTrigger.cpp
    
)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        YQ_USE_GLM=1
    PRIVATE 
        "-DYQ_DATA_DIR=\"${YQ_TACHYON_DATA_DIR}\"" 
        VK_ENABLE_BETA_EXTENSIONS=1
        DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
        DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/public
    ${CMAKE_CURRENT_LIST_DIR}/../../api
    ${VULQAN_API_DIR}
)


target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_asset
    yq_color
    yq_gui3rd
    yq_imgui 
    yq_keyv
    yq_process
    yq_raster
    yq_stb 
    yq_vma

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)
