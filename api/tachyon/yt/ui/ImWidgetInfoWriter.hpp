////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/ImWidget.hpp>
#include <yt/2D/Widget2InfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class ImWidgetInfo::Writer : public Widget²Info::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ImWidgetInfo* widgetInfo) : Widget²Info::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ImWidgetInfo& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        ImWidgetInfo* m_meta;
    };
}
