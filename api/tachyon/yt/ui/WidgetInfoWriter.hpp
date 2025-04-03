////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class WidgetInfo::Writer : public TachyonInfo::Writer<C>, public UIElementWriter {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(WidgetInfo* widgetInfo) : TachyonInfo::Writer<C>(widgetInfo), UIElementWriter(*widgetInfo), m_meta(widgetInfo)
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
        
        //! Annotates that this widget will render Vulkan content
        void    vulkan()
        {
            Meta::Writer::options({Flag::VULKAN});
        }

    private:
        WidgetInfo* m_meta;
    };
}
