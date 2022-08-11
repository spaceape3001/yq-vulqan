if(NOT TARGET stb)
    set(stb_dir ${CMAKE_CURRENT_LIST_DIR}/stb)
    add_library(stb SHARED
        ${CMAKE_CURRENT_LIST_DIR}/stb.cpp
    )
    target_include_directories(stb PUBLIC ${stb_dir})
endif()

