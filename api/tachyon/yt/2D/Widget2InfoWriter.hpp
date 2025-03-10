////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/2D/Widget2.hpp>
#include <yt/2D/Widget2Data.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class Widget²Info::Writer : public WidgetInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(Widget²Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(Widget²Info& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        Widget²Info* m_meta;
    };
}
