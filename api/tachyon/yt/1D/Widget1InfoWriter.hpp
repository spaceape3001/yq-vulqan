////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/1D/Widget1.hpp>
#include <yt/1D/Widget1Data.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class Widget¹Info::Writer : public WidgetInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(Widget¹Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(Widget¹Info& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        Widget¹Info* m_meta;
    };
}
