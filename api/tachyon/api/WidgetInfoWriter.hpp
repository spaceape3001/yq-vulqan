////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <tachyon/api/WidgetData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/ui/UIAppMainWriter.hpp>
#include <tachyon/typedef/uielement.hpp>

namespace yq::tachyon {

    class UIElementsWriter;
    class UIAppMainWriter;

    /*! \brief Writer of widget information
    */
    template <typename C>
    class WidgetInfo::Writer : public TachyonMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(WidgetInfo* widgetInfo) : TachyonMeta::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
        {
        }

        //! Annotates that this widget will render IMGUI content
        void    imgui()
        {
            Meta::Writer::options({Flag::IMGUI});
        }
        
        UIElementsWriter imgui(ui_k)
        {
            imgui();
            return UIElementsWriter(m_meta);
        }
        
        UIAppMainWriter imgui(ui_k, app_k)
        {
            imgui();
            return UIAppMainWriter(m_meta);
        }
        
        template <SomeUIElement U>
        typename U::Writer    imgui(ui_k, U* ui)
        {
            if(!ui)
                return {};
            if(!m_meta){
                delete ui;
                return {};
            }
            
            imgui();
            m_meta -> m_ui = ui;
            return typename U::Writer(ui);
        }
        
        //! Loads the specified UI file, instantiates it (TODO)
        void    imgui(ui_k, std::string_view);

        //! Annotates that this widget will render Vulkan content
        void    vulkan()
        {
            Meta::Writer::options({Flag::VULKAN});
        }

    private:
        WidgetInfo* m_meta;
    };
}
