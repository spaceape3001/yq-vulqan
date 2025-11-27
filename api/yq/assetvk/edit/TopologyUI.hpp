////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class TopologyUI : public UIEditor {
        YQ_OBJECT_DECLARE(TopologyUI, UIEditor)
    public:
        TopologyUI(UIFlags flags={});
        TopologyUI(const TopologyUI&);
        
        virtual TopologyUI* clone() const;
        
        void    topology();
        
        static void init_meta();
    };
}
