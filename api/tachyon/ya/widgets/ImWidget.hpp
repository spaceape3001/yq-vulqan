////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/2D/Widget2.hpp>

namespace yq::tachyon {

    class ImWidgetInfo : public Widget²Info {
    public:
    
        template <typename> class Writer;
        
        ImWidgetInfo(std::string_view, Widget²Info&, const std::source_location& sl = std::source_location::current());
    
    };


    /*! \brief A widget defined in ImGui that needs external 2D sizing
    
        This can be a toolbar itself, a floating window, etc...
    */
    class ImWidget : public Widget² {
        YQ_TACHYON_INFO(ImWidgetInfo)
        YQ_TACHYON_DECLARE(ImWidget, Widget²)
    public:
        
        ImWidget();
        ~ImWidget();
        
        static void init_info();
    
        //! The imgui wrapper
        virtual void    imgui(ViContext&) override final;
        
        //! Override this for content (begin/end are already taken care of)
        virtual void    imguix(ViContext&) = 0;
    };
}
