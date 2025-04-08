////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAppMain.hpp"

namespace yq::tachyon {
    UIAppMain::UIAppMain(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIAppMain::UIAppMain(const UIAppMain& cp) : UIElements(cp)
    {
    }
    
    UIAppMain::~UIAppMain()
    {
    }
    
    UIAppMain* UIAppMain::clone() const
    {
        return new UIAppMain(*this);
    }
}
