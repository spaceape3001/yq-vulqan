////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox1.hpp>
#include <yq/shape/Size1.hpp>
#include <yt/ui/SizePolicy.hpp>

namespace yq::tachyon {
    struct Layout¹Snap {
        AxBox1D     aabb = ZERO;
        Size1D      minsize = ZERO, maxsize = ZERO;
        SizePolicy¹ sizing;
        
        virtual ~Layout¹Snap(){}
    };
}


