////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Which face is front
    
        This indicates to the GPU which face of a triangle is "front side" for rendering or not.
        Combined with the cull mode, this can speed up rendering by telling the pipeline to 
        skip a face based on this orientation.
    */
    YQ_ENUM(FrontFace, , 
        CounterClockwise    = 0,
        Clockwise = 1
    )
}
YQ_TYPE_DECLARE(yq::tachyon::FrontFace)
