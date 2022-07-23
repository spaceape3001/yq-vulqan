file( GLOB stb_dir stb-*)
add_library(stb INTERFACE)
target_sources(stb INTERFACE
    ${stb_dir}/stb_image.h
)
target_include_directories(stb INTERFACE ${stb_dir})

file( GLOB vma_dir vma-*)
add_library(vma INTERFACE)
target_sources(vma INTERFACE
    ${vma_dir}/include/vk_mem_alloc.h
)
target_include_directories(stb INTERFACE ${vma_dir}/include)

