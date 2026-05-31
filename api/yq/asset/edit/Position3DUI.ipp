////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition3D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³DUI)

namespace yq::tachyon {
    void Position³DUI::init_meta()
    {
        auto w = writer<Position³DUI>();
        w.description("UIEditor for Position³");
        w.edits<PPosition³D>();
        w.field("Position", &Position³DUI::position);
    }
    
    Position³DUI::Position³DUI(UIFlags flags)
    {
    }
    
    Position³DUI::Position³DUI(const Position³DUI& cp) : UIEditor(cp)
    {
    }
    
    Position³DUI* Position³DUI::clone() const
    {
        return new Position³DUI(*this);
    }

    void    Position³DUI::position()
    {
        PPosition³D* p   = snap()->proxy<PPosition³D>();
        if(!p)
            return ;
            
        Vector3D    v   = p->position();
        if(im::input("##position", v))
            p -> position(SET, v);
    }
}
