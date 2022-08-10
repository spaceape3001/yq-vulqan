################################################################################
##
##  YOUR QUILL
##
################################################################################

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(asset_test_source ./test.cpp)
endif()

set(yq_asset_sources
    ${asset_test_source}
    
    ./asset.cpp
)

add_library(yqasset SHARED ${yq_asset_sources})
target_link_libraries(yqasset PUBLIC  yqengine)
LinkTest(yqasset)


