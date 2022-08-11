if(NOT TARGET vma)
    set(vma_dir ${CMAKE_CURRENT_LIST_DIR}/vma)
    add_library(vma SHARED
        ${CMAKE_CURRENT_LIST_DIR}/vma.cpp
    )
    target_compile_options(vma PRIVATE 
        -w
    )
    target_include_directories(vma PUBLIC ${vma_dir}/include)
endif()

