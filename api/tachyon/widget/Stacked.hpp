////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Stacked Widget
    
        This is a selector of widgets, will show/render the Nth child widget.
    */
    class Stacked : public Widget {
        YQ_OBJECT_DECLARE(Stacked, Widget)
    public:

        Widget*         active();
        const Widget*   active() const;
        size_t          index() const { return m_active; }
        void            set_active(size_t);
        
        virtual void    imgui_(ViContext&) override;
        virtual void    vulkan_(ViContext&) override;

        Stacked();
        ~Stacked();
    
    private:
        size_t          m_active    = 0;
    };
}
