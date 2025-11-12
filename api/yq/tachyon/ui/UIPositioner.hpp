////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class UIPositionerWriter;

    /*! \brief  UI Position Calculator
    
        This is a little helper UI thing to control positions (of whatever).  
        It's effectively a "delegate", not a strict UI ImGui element, 
        however, we need the internals available to the UIElement.
        
        \note This should *ONLY* be subclassed to windows (and the first one 
        attached will win).
    */
    class UIPositioner : public UIElement {
        YQ_OBJECT_DECLARE(UIPositioner, UIElement)
    public:
    
        using Writer = UIPositionerWriter;
    
        UIPositioner();
        UIPositioner(const UIPositioner&);
        virtual ~UIPositioner();
        
        static void init_meta();
        
        void render() override final {} // positioners do not render
        
        //! Computes the position (use it)
        virtual AxBox2F         position() = 0;
        virtual UIPositioner*   clone() const override = 0;
        
    protected:
        Vector2F    m_position  = NAN;
        AxBox2F     m_bounds    = NAN;
        Sise2F      m_size      = NAN;
        
    };
}
