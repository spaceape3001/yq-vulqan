////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICenterAlign.hpp"
#include "UICenterAlignWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICenterAlign)

namespace yq::tachyon {
    void UICenterAlign::init_meta()
    {
        auto w = writer<UICenterAlign>();
        w.description("UI Element that centers its contents");
    }

    UICenterAlign::UICenterAlign(UIFlags flags) : UIElements(flags)
    {
    }
    
    UICenterAlign::UICenterAlign(const UICenterAlign& cp) : UIElements(cp)
    {
    }
    
    UICenterAlign::~UICenterAlign()
    {
    }
    
    UICenterAlign* UICenterAlign::clone() const
    {
        return new UICenterAlign(*this);
    }

    void        UICenterAlign::render()
    {
        if(m_width > 0)
            ImGui::Dummy({ m_width, 1 });
        Vector2F    b   = ImGui::GetCursorPos();
        content();
        Vector2F    c   = ImGui::GetCursorPos();
        float       x   = 0.5*(b.x+c.x);
        m_width        += ImGui::GetWindowWidth()*0.5 - x;
    }

    ////////////////////////////

    UICenterAlignWriter::UICenterAlignWriter() = default;
    UICenterAlignWriter::UICenterAlignWriter(const UICenterAlignWriter&) = default;
    UICenterAlignWriter::~UICenterAlignWriter() = default;

    UICenterAlign* UICenterAlignWriter::element()
    {
        return static_cast<UICenterAlign*>(m_ui);
    }
    
    UICenterAlignWriter::UICenterAlignWriter(UICenterAlign* ui) : UIElementsWriter(ui)
    {
    }

}
