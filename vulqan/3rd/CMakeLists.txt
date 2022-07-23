
file( GLOB vma_dir vma-*)
add_library(vma INTERFACE)
target_sources(vma INTERFACE
    ${vma_dir}/include/vk_mem_alloc.h
)
target_include_directories(vma INTERFACE ${vma_dir}/include)

