////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class UICalcWriter;

    /*! \brief  UI Position/Whatever Calculator
    
        This is a little helper UI thing to control positions (of whatever).  
        It's effectively a "delegate", not a strict UI ImGui element, 
        however, we need the internals available to the UIElement.
        
        \note This should *ONLY* be children to windows.
    */
    class UICalc : public UIElement {
        YQ_OBJECT_DECLARE(UICalc, UIElement)
    public:
    
        using Writer = UICalcWriter;
    
        UICalc();
        UICalc(const UICalc&);
        virtual ~UICalc();
        
        static void init_meta();
        
        void render() override final {} // calcs do not render
        virtual void calculate(){}      // Will be called *POST* render inside the window
        virtual UICalc*   clone() const override = 0;
    };
}
