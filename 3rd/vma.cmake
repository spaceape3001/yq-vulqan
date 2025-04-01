if(NOT TARGET VulkanMemoryAllocator)
    set(vma_dir ${CMAKE_CURRENT_LIST_DIR}/vma)
    add_library(VulkanMemoryAllocator SHARED
        ${CMAKE_CURRENT_LIST_DIR}/vma.cpp
    )
    target_compile_options(VulkanMemoryAllocator PRIVATE 
        -w
    )
    target_include_directories(VulkanMemoryAllocator PUBLIC ${vma_dir}/include)
endif()

