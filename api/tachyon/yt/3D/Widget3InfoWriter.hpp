////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Widget3.hpp>
#include <yt/3D/Widget3Data.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class Widget³Info::Writer : public WidgetInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(Widget³Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(Widget³Info& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        Widget³Info* m_meta;
    };
}
