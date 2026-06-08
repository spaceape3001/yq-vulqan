////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/api/Rendered3Data.hpp>

namespace yq::tachyon {
    class Shape³Snap : public Rendered³Snap {
        YQ_OBJECT_DECLARE(Shape³Snap, Rendered³Snap)
    public:
        Shape³Snap();
        virtual ~Shape³Snap();
        
        Tristate    auto_center;
        Tristate    normalize;

        static void init_meta();
    };

    class Shape³Data : public Rendered³Data {
        YQ_OBJECT_DECLARE(Shape³Data, Rendered³Data)
    public:
    
        Shape³Data();
        virtual ~Shape³Data();
        
        static void init_meta();
    };
}
