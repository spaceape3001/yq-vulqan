################################################################################
##
##  YOUR QUILL
##
################################################################################

project(tachyon)

add_subdirectory(3rd)

set(VULQAN_API_DIR ${CMAKE_CURRENT_LIST_DIR})
set(VULQAN_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(yq-vulqan)


if(NOT_GOING_TO_HAPPEN)
    if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
        set(test_source ./test.cpp)
    endif()


    add_library(${PROJECT_NAME} SHARED 
        ${test_source}

        ./tachyon/tachyon.cpp
        ./tachyon/enum/enum.cpp
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
    target_link_libraries(${PROJECT_NAME} 
        PUBLIC  
            yqtoolbox
            vma 
            stb
            ${Vulkan_LIBRARIES} 
            ${GLFW3_LIBRARY}
            gui3rd
            imgui
            yqvulqan
    )

    target_include_directories(${PROJECT_NAME} 
        PUBLIC 
            ${CMAKE_CURRENT_LIST_DIR}
            ${glm_INCLUDE_DIR}
            yqvulqan
    )

    LinkTest(${PROJECT_NAME})
endif()



