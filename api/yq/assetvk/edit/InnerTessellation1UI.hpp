////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class InnerTessellation¹UI : public UIEditor {
        YQ_OBJECT_DECLARE(InnerTessellation¹UI, UIEditor)
    public:
        InnerTessellation¹UI(UIFlags flags={});
        InnerTessellation¹UI(const InnerTessellation¹UI&);
        
        virtual InnerTessellation¹UI* clone() const;
        
        void    inner_tessellation();
        
        static void init_meta();
    };
}
