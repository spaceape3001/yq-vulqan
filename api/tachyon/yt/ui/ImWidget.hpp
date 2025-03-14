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
    
    class TitleCommand;


    /*! \brief A widget defined in ImGui that needs external 2D sizing
    
        This can be a toolbar itself, a floating window, etc...
    */
    class ImWidget : public Widget² {
        YQ_TACHYON_INFO(ImWidgetInfo)
        YQ_TACHYON_DECLARE(ImWidget, Widget²)
    public:
        
        static void init_info();
    
        //! The imgui wrapper
        virtual void    imgui(ViContext&) override final;
        
        //! Override this for content (begin/end are already taken care of)
        virtual void    imguix(ViContext&) = 0;
        
        void    set_title(std::string_view);
        
    protected:
        ImWidget(std::string_view kTitle={});
        ~ImWidget();
        
    private:
        std::string     m_title;
        
        enum class X {
            Open,
            CloseTab
        };
        
        Flags<X>        m_flags;
        
        void    on_title_command(const TitleCommand&);
    };
}
