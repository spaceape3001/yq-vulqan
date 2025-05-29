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
    set(GLOBAL PROPERTY YQ_VULQAN_DATA)  
    
    #   Use this macro for non-tachyon libraries
    macro(vulqan_library target)
        message("vulkan library ${target}")
        get_property(tmp GLOBAL PROPERTY YQ_VULQAN_LIBRARIES)
        #get_target_property(tgt ${target} LIBRARY_OUTPUT_NAME)
        list(APPEND tmp ${target})
        set_property(GLOBAL PROPERTY YQ_VULQAN_LIBRARIES ${tmp})
    endmacro()
    macro(vulqan_data dir)
        set(full "${CMAKE_CURRENT_LIST_DIR}/${dir}")
        message("vulkan data ${full}")
        get_property(tmp GLOBAL PROPERTY YQ_VULQAN_DATA)
        #get_target_property(tgt ${target} LIBRARY_OUTPUT_NAME)
        list(APPEND tmp ${full})
        set_property(GLOBAL PROPERTY YQ_VULQAN_DATA ${tmp})
    endmacro()

    macro(vulqan_config)
        if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_LIST_DIR})
            get_property(VULQAN_LIBARIES GLOBAL PROPERTY YQ_VULQAN_LIBRARIES)
            get_property(VULQAN_DATA GLOBAL PROPERTY YQ_VULQAN_DATA)
            configure_file(${VULQAN_DIR}/vulqan.cfg.in ${CMAKE_BINARY_DIR}/bin/vulqan.cfg)
        endif()
    endmacro()
endif()


set(YQ_TACHYON_DATA_DIR "${CMAKE_CURRENT_LIST_DIR}/data" )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})
