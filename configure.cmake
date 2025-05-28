################################################################################
##
##  YOUR QUILL
##
################################################################################

if(NOT YOUR_QUILL_VULQAN)
    SET(YOUR_QUILL_VULQAN ${CMAKE_CURRENT_LIST_DIR})
endif()

if(NOT COMMAND vulkan_library)
    #   Append for all vulkan based libraries
    set(GLOBAL PROPERTY YQ_VULQAN_LIBRARIES)  
    
    #   Use this macro for non-tachyon libraries
    macro(vulkan_library target)
        message("vulkan library ${target}")
        get_property(tmp GLOBAL PROPERTY YQ_VULQAN_LIBRARIES)
        #get_target_property(tgt ${target} LIBRARY_OUTPUT_NAME)
        list(APPEND tmp ${target})
        set_property(GLOBAL PROPERTY YQ_VULQAN_LIBRARIES ${tmp})
    endmacro()

    macro(vulkan_config)
        if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_LIST_DIR})
            get_property(VULQAN_LIBARIES GLOBAL PROPERTY YQ_VULQAN_LIBRARIES)
            configure_file(${VULQAN_DIR}/vulqan.cfg.in ${CMAKE_BINARY_DIR}/bin/vulqan.cfg)
        endif()
    endmacro()
endif()


set(YQ_TACHYON_DATA_DIR "${CMAKE_CURRENT_LIST_DIR}/data" )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})
