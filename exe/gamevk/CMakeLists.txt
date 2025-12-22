################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(gamevk 
    main.cpp
)
target_link_libraries(gamevk PUBLIC yq_lua yq_luavk yq_tachyon)
