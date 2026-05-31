################################################################################
##
##  YOUR QUILL
##
################################################################################

#   There's going to be *some* confusion to the correct library, however, the
#   single tree seemed more important.

include(assetvk.cmake)
include(assetphys.cmake)
include(assetgame.cmake)

if(Build_Qt6)
    include(assetqt.cmake)
endif()
