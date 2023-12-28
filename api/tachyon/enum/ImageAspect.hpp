////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/basic/Flag.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ImageAspect, ,
        Color           =  0,
        Depth           =  1,
        Stencil         =  2,
        MetaData        =  3,
        Plane0          =  4,
        Plane1          =  5,
        Plane2          =  6,
        MemoryPlane0    =  7,
        MemoryPlane1    =  8,
        MemoryPlane2    =  9,
        MemoryPlane3    = 10
    )
    
    using ImageAspectFlags  = Flag<ImageAspect>;
}

YQ_TYPE_DECLARE(yq::tachyon::ImageAspect)
YQ_TYPE_DECLARE(yq::tachyon::ImageAspectFlags)
