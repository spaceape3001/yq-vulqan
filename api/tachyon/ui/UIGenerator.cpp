////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIGenerator.hpp"
#include <tachyon/api/UIElementInfoWriter.hpp>
#include <yq/container/vector_utils.hpp>
#include <yq/core/Ref.hpp>
#include <tachyon/api/Action.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIGenerator)

namespace yq::tachyon {
    UIGenerator::UIGenerator(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIGenerator::~UIGenerator()
    {
    }

    UIElement* UIGenerator::copy() const 
    {
        UIElement*  ret = clone();
        if(!ret)
            return nullptr;
        ret -> m_actions       += m_actions;
        ret -> m_flags         |= m_flags;
        if(!ret->m_bId)
            ret -> m_bId        = m_bId;
        if(ret->m_uId.empty())
            ret -> m_uId        = m_uId;
        ret -> update(FLAGS);
        return ret;
    }
    
    Tristate UIGenerator::is(const UIElementInfo& baseInfo) const 
    {
        if(UIElement::is(baseInfo) == Tristate::YES)
            return Tristate::YES;
        
        const UIElementInfo*    genInfo = ui_info();
        if(!genInfo)
            return Tristate::Indeterminant;
        
        if(genInfo->is_base(baseInfo) || genInfo->is_this(baseInfo))
            return Tristate::YES;
        if(genInfo->is_derived(baseInfo))       // so, could be... maybe
            return Tristate::Indeterminant;
        return Tristate::NO;
    }

    void UIGenerator::init_info()
    {
        auto w = writer<UIGenerator>();
        w.description("UI Element Generator");
    }
}
