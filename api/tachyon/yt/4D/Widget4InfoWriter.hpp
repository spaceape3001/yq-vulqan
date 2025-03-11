////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/4D/Widget4.hpp>
#include <yt/4D/Widget4Data.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class Widget⁴Info::Writer : public WidgetInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(Widget⁴Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(Widget⁴Info& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        Widget⁴Info* m_meta;
    };
}
