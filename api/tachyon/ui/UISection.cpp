////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UISection.hpp"
#include <tachyon/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UISection)

namespace yq::tachyon {
    void UISection::init_info()
    {
        auto w = writer<UISection>();
        w.description("UI Section");
        w.property("title", &UISection::m_title);
    }
    
    UISection::UISection(std::string_view sz, UIFlags flags) : UIElements(flags), m_title(sz)
    {
    }
    
    UISection::UISection(const UISection& cp) : UIElements(cp), m_title(cp.m_title)
    {
    }
    
    UISection::~UISection()
    {
    }
    
    UISection* UISection::clone() const 
    {
        return new UISection(*this);
    }
    
    const char* UISection::title() const
    {
        return m_title.c_str();
    }
}
