if(NOT TARGET yq_vma)
    set(vma_dir ${CMAKE_CURRENT_LIST_DIR}/vma)
    add_library(yq_vma SHARED
        ${CMAKE_CURRENT_LIST_DIR}/vma.cpp
    )
    target_compile_options(yq_vma PRIVATE 
        -w
    )
    target_include_directories(yq_vma PUBLIC ${vma_dir}/include)
endif()

