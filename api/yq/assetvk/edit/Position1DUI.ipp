////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position1DUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition1D.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position¹DUI)

namespace yq::tachyon {
    void Position¹DUI::init_meta()
    {
        auto w = writer<Position¹DUI>();
        w.description("UIEditor for Position¹ (double)");
        w.edits<PPosition¹D>();
        w.field("Position", &Position¹DUI::position);
    }
    
    Position¹DUI::Position¹DUI(UIFlags flags)
    {
    }
    
    Position¹DUI::Position¹DUI(const Position¹DUI& cp) : UIEditor(cp)
    {
    }
    
    Position¹DUI* Position¹DUI::clone() const
    {
        return new Position¹DUI(*this);
    }

    void    Position¹DUI::position()
    {
        PPosition¹D* p   = snap()->proxy<PPosition¹D>();
        if(!p)
            return ;
            
        Vector1D    v   = p->position();
        if(im::input("##position", v))
            p -> position(SET, v);
    }
}
