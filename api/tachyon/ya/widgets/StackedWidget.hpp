////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {

    /*! \brief StackedWidget Widget
    
        This is a selector of widgets, will show/render the Nth child widget.
    */
    class StackedWidget : public Widget {
        YQ_TACHYON_DECLARE(StackedWidget, Widget)
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
        virtual void    imgui(ViContext&) override;

        //! Renders vulkan data
        virtual void    vulkan(ViContext&) override;

        //! Default constructor
        StackedWidget();
        
        //! Default destructor
        ~StackedWidget();
        
        static void init_info();
    
    private:
        size_t          m_active    = 0;
    };
}
