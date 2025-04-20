////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UILayout.hpp"
#include "UILayoutWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/logging.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UILayout)

namespace yq::tachyon {
    void UILayout::init_info()
    {
        auto w = writer<UILayout>();
        w.description("UI Layout");
    }
    
    UILayout::UILayout(UIFlags flags) : UIElements(flags)
    {
    }
    
    UILayout::UILayout(const UILayout& cp) : UIElements(cp)
    {
    }
    
    UILayout::~UILayout()
    {
    }
    
    UILayout*       UILayout::clone() const
    {
        return new UILayout(*this);
    }
    
    ////////////////////////////
    
    UILayoutWriter::UILayoutWriter() = default;
    UILayoutWriter::UILayoutWriter(const UILayoutWriter&) = default;
    UILayoutWriter::~UILayoutWriter() = default;
    
    UILayout* UILayoutWriter::element()
    {
        return static_cast<UILayout*>(m_ui);
    }
    
    UILayoutWriter::UILayoutWriter(UILayout* ui) : UIElementsWriter(ui)
    {
    }

}
