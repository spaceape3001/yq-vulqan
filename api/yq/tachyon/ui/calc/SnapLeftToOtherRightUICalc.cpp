////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SnapLeftToOtherRightUICalc.hpp"
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SnapLeftToOtherRightUICalc)

namespace yq::tachyon {
    void SnapLeftToOtherRightUICalc::init_meta()
    {
        auto w = writer<SnapLeftToOtherRightUICalc>();
        w.description("UI Calculator to set parent's left to other window's right edge");
    }

    SnapLeftToOtherRightUICalc::SnapLeftToOtherRightUICalc(uint64_t b, UIFlags flags) : UICalc(flags), m_bId(b)
    {
    }
    
    SnapLeftToOtherRightUICalc::SnapLeftToOtherRightUICalc(const SnapLeftToOtherRightUICalc& cp) : UICalc(cp), m_bId(cp.m_bId)
    {
    }
    
    SnapLeftToOtherRightUICalc::~SnapLeftToOtherRightUICalc()
    {
    }
    
    SnapLeftToOtherRightUICalc* SnapLeftToOtherRightUICalc::clone() const 
    {
        return new SnapLeftToOtherRightUICalc(*this);
    }
    
    void    SnapLeftToOtherRightUICalc::calculate() 
    {
        Widget*w        = widget();
        if(!w)
            return;
            
        UIWindow*   us  = dynamic_cast<UIWindow*>(parent());
        if(!us)
            return;
            
        UIWindow*   win = dynamic_cast<UIWindow*>(w->element(FIRST, m_bId));
        if(!win)
            return ;
        
        us->x(SET, NEXT, win->right());
    }
}
