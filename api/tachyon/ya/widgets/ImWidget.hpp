////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/2D/Widget2.hpp>

namespace yq::tachyon {

    /*! \brief A widget defined in ImGui that needs external 2D sizing
    
        This can be a toolbar itself, a floating window, etc...
    */
    class ImWidget : public Widget² {
        YQ_TACHYON_DECLARE(ImWidget, Widget²)
    public:
    
        //! The imgui wrapper
        virtual void    imgui(ViContext&) override final;
        
        //! Override this for content (begin/end are already taken care of)
        virtual void    imguix(ViContext&) = 0;
    };
}
