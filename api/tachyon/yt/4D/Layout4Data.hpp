////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox4.hpp>
#include <yq/shape/Size4.hpp>
#include <yt/ui/SizePolicy.hpp>

namespace yq::tachyon {
    struct Layout⁴Snap {
        AxBox4D     aabb = ZERO;
        Size4D      minsize = ZERO, maxsize = ZERO;
        SizePolicy⁴ sizing;
        
        virtual ~Layout⁴Snap(){}
    };
}


