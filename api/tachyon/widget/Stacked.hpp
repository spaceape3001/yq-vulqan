////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Stacked Widget
    
        This is a selector of widgets, will show/render the Nth child widget.
    */
    class Stacked : public Widget {
        YQ_OBJECT_DECLARE(Stacked, Widget)
    public:

        //! Active widget
        Widget*         active();

        //! Active widget
        const Widget*   active() const;

        //! Current index
        size_t          index() const { return m_active; }
        
        //! Sets the current index
        void            set_active(size_t);
        
        //! Renders imgui data
        virtual void    imgui_(ViContext&) override;

        //! Renders vulkan data
        virtual void    vulkan_(ViContext&) override;

        //! Default constructor
        Stacked();
        
        //! Default destructor
        ~Stacked();
    
    private:
        size_t          m_active    = 0;
    };
}
