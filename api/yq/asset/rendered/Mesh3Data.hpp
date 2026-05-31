////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/enum/AxisRemap.hpp>
#include <yq/tachyon/rendered/Shape3Data.hpp>

namespace yq::tachyon {
    struct Mesh³Snap : public Shape³Snap {
    
        AxisRemap       axis;
    
        Mesh³Snap();
        virtual ~Mesh³Snap();
    };
}
