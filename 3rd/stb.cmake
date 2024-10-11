if(NOT TARGET yq_stb)
    set(stb_dir ${CMAKE_CURRENT_LIST_DIR}/stb)
    add_library(yq_stb SHARED
        ${CMAKE_CURRENT_LIST_DIR}/stb.cpp
    )
    target_include_directories(yq_stb PUBLIC ${stb_dir})
endif()

