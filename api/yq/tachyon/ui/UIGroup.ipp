////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIGroup.hpp"
#include "UIGroupWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIGroup)

namespace yq::tachyon {
    void UIGroup::init_meta()
    {
        auto w = writer<UIGroup>();
        w.description("Group of UI Elements");
    }

    UIGroup::UIGroup(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIGroup::UIGroup(const UIGroup& cp) : UIElements(cp)
    {
    }
    
    UIGroup::~UIGroup()
    {
    }
    
    UIGroup* UIGroup::clone() const
    {
        return new UIGroup(*this);
    }

    void    UIGroup::render() 
    {
        ImGui::BeginGroup();
        content();
        ImGui::EndGroup();
    }

    ////////////////////////////

    UIGroupWriter::UIGroupWriter() = default;
    UIGroupWriter::UIGroupWriter(const UIGroupWriter&) = default;
    UIGroupWriter::~UIGroupWriter() = default;

    UIGroup* UIGroupWriter::element()
    {
        return static_cast<UIGroup*>(m_ui);
    }
    
    UIGroupWriter::UIGroupWriter(UIGroup* ui) : UIElementsWriter(ui)
    {
    }

}

