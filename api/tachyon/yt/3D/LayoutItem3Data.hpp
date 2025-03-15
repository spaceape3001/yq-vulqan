////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox3.hpp>
#include <yq/shape/Size3.hpp>
#include <yt/ui/SizePolicy.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    struct LayoutItem³Snap {
        AxBox3D     aabb = ZERO;
        Size3D      minsize = NAN, maxsize = NAN;
        SizePolicy³ sizing;
        
        virtual ~LayoutItem³Snap(){}
    };
}


