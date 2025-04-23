////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIGenerator.hpp"
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIGenerator)

namespace yq::tachyon {
    UIGenerator::UIGenerator(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIGenerator::~UIGenerator()
    {
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
