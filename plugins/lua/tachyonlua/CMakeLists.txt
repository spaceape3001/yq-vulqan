################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(tachyonlua SHARED 
    tachyon.cpp
)
target_link_libraries(tachyonlua PUBLIC yq_lua yq_luavk yq_tachyon)
LinkTest(tachyonlua)
