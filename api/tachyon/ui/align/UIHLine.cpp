////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHLine.hpp"
#include "UIHLineWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIHLine)

namespace yq::tachyon {
    void UIHLine::init_meta()
    {
        auto w = writer<UIHLine>();
        w.description("Horizontal line of UI elements");
    }

    UIHLine::UIHLine(UIFlags flags) : UIElements(flags|UIFlag::Horizontal)
    {
    }
    
    UIHLine::UIHLine(const UIHLine& cp) : UIElements(cp)
    {
    }
    
    UIHLine::~UIHLine()
    {
    }
    
    UIHLine* UIHLine::clone() const
    {
        return new UIHLine(*this);
    }

    ////////////////////////////

    UIHLineWriter::UIHLineWriter() = default;
    UIHLineWriter::UIHLineWriter(const UIHLineWriter&) = default;
    UIHLineWriter::~UIHLineWriter() = default;

    UIHLine* UIHLineWriter::element()
    {
        return static_cast<UIHLine*>(m_ui);
    }
    
    UIHLineWriter::UIHLineWriter(UIHLine* ui) : UIElementsWriter(ui)
    {
    }

}

