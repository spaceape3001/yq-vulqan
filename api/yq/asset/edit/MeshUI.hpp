////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class MeshUI : public UIEditor {
        YQ_OBJECT_DECLARE(MeshUI, UIEditor)
    public:
        MeshUI(UIFlags flags={});
        MeshUI(const MeshUI&);
        
        virtual MeshUI* clone() const;
        
        void    mesh();
        
        static void init_meta();
    };
}
