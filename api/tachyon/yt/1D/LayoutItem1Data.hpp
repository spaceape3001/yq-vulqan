////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/AxBox1.hpp>
#include <yq/shape/Size1.hpp>
#include <yt/ui/SizePolicy.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    struct LayoutItem¹Snap {
        AxBox1D     aabb    = ZERO;
        Size1D      minsize = NAN;
        Size1D      maxsize = NAN;
        Size1D      hint    = NAN;
        SizePolicy¹ sizing;
        
        virtual ~LayoutItem¹Snap(){}
    };
}


