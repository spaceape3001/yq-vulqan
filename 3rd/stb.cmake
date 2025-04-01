if(NOT TARGET STBImage)
    add_library(STBImage SHARED
        ${CMAKE_CURRENT_LIST_DIR}/stb.cpp
    )
    target_include_directories(STBImage PUBLIC ${CMAKE_CURRENT_LIST_DIR}/stb)
endif()

