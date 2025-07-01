////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderedUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/RenderedData.hpp>
#include <tachyon/command/rendered/SetWireframeCommand.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RenderedUI)

namespace yq::tachyon {
    
    void RenderedUI::init_meta()
    {
        auto w = writer<RenderedUI>();
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


    void    RenderedUI::wireframe()
    {
        const RenderedSnap*  sn    = dynamic_cast<const RenderedSnap*>(snap());
        if(!sn)
            return ;
            
        std::string     sid = std::format("##Wireframe{}", bound().id);
        Tristate        v  = sn->wireframe;
        
        if(ImGui::Checkbox(sid.c_str(), v)){
            send(new SetWireframeCommand({.target=sn->self}, v));
        }
    }

}
