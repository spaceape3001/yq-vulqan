////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Size2.hpp>
#include <yt/ui/SizePolicy.hpp>

namespace yq::tachyon {
    struct LayoutItem²Snap {
        AxBox2D     aabb = ZERO;
        Size2D      minsize = ZERO, maxsize = ZERO;
        SizePolicy² sizing;
        
        virtual ~LayoutItem²Snap(){}
    };
}


