////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/api/Rendered3Data.hpp>

namespace yq::tachyon {
    struct Shape³Snap : public Rendered³Snap {
        Shape³Snap();
        virtual ~Shape³Snap();
        
        Tristate    auto_center;
        Tristate    normalize;
    };

    struct Shape³Data : public Rendered³Data {
        Shape³Data();
        virtual ~Shape³Data();
    };
}
