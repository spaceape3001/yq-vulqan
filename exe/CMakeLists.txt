################################################################################
##
##  YOUR QUILL
##
################################################################################

add_subdirectory(scenery)
add_subdirectory(luavk)
add_subdirectory(xgvk)
add_subdirectory(gltf)
add_subdirectory(obj)
add_subdirectory(gamevk)

if(Build_Qt6)
    add_subdirectory(sceneqt)
    add_subdirectory(xgqt)
endif()
