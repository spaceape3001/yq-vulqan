////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Size3.hpp>
#include <yt/ui/SizePolicy.hpp>

namespace yq::tachyon {
    struct Layout³Snap {
        AxBox3D     aabb = ZERO;
        Size3D      minsize = ZERO, maxsize = ZERO;
        SizePolicy³ sizing;
        
        virtual ~Layout³Snap(){}
    };
}


