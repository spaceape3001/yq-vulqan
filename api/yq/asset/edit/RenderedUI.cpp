////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderedUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/command/rendered/SetWireframeCommand.hpp>
#include <yq/tachyon/im/checkbox.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RenderedUI)

namespace yq::tachyon {
    
    void RenderedUI::init_meta()
    {
        auto w = writer<RenderedUI>();
        w.field("Good", &RenderedUI::good);
        w.field("Wireframe", &RenderedUI::wireframe);
        w.edits<Rendered>();
    }

    RenderedUI::RenderedUI(UIFlags flags) : UIEditor(flags)
    {
    }

    RenderedUI::RenderedUI(const RenderedUI& cp) : UIEditor(cp)
    {
    }
    
    RenderedUI::~RenderedUI()
    {
    }
    
    RenderedUI*  RenderedUI::clone() const 
    {
        return new RenderedUI(*this);
    }

    void    RenderedUI::good()
    {
        const RenderedSnap*  sn    = dynamic_cast<const RenderedSnap*>(snap());
        if(!sn)
            return ;
        ImGui::SetNextItemWidth(-1);
        ImGui::TextUnformatted(sn->good?"GOOD":"BAD");
    }
    
    void    RenderedUI::wireframe()
    {
        const RenderedSnap*  sn    = dynamic_cast<const RenderedSnap*>(snap());
        if(!sn)
            return ;
            
        std::string     sid = std::format("##Wireframe{}", bound().id);
        Tristate        v  = sn->wireframe;
        
        ImGui::SetNextItemWidth(-1);
        if(im::checkbox(sid.c_str(), v)){
            send(new SetWireframeCommand({.target=sn->self}, v));
        }
    }

}
