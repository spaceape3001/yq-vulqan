################################################################################
##
##  YOUR QUILL
##
################################################################################

##  For the longest time, the tachyon was the *ONLY* library, however, it's ...
##  grown.  Therefore, we're spinning things.  Focused/assets are in their
##  own independent libraries.  Tachyon/Asset will still be default locations
##  until there's a better spot for (fill-in-the-blank)

##  Note: EVERYTHING IN THIS SUBDIRECTORY SHOULD BE USING THE yq::tachyon namespace!

##  This is the MAIN vulkan library, it's always first
add_subdirectory(tachyon)

##  Asset are general things that most apps will be interested in
add_subdirectory(assetvk)

##  A simple console (ImGui based)
add_subdirectory(consolevk)

##  A 2D canvas type of thing
add_subdirectory(canvasvk)

##  Graph
add_subdirectory(graphvk)

##  Lua
add_subdirectory(luavk)

##  Executive Graph
add_subdirectory(xgvk)

##  Game stuff
add_subdirectory(gamevk)

## Scene Editor
add_subdirectory(editorvk)

if(Build_Qt6)
    add_subdirectory(vkqt)
    add_subdirectory(assetqt)
    add_subdirectory(xgqt)
endif()

