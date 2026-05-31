////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class InnerTessellation²UI : public UIEditor {
        YQ_OBJECT_DECLARE(InnerTessellation²UI, UIEditor)
    public:
        InnerTessellation²UI(UIFlags flags={});
        InnerTessellation²UI(const InnerTessellation²UI&);
        
        virtual InnerTessellation²UI* clone() const;
        
        void    inner_tessellation();
        
        static void init_meta();
    };
}
