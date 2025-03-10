////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Layout.hpp>
#include <yt/api/DelegateInfoWriter.hpp>

namespace yq::tachyon {

    /*! \brief Writer of widget information
    */
    template <typename C>
    class LayoutInfo::Writer : public DelegateInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(LayoutInfo* widgetInfo) : DelegateInfo::Writer<C>(widgetInfo), m_meta(widgetInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(LayoutInfo& widgetInfo) : Writer(&widgetInfo)
        {
        }

    private:
        LayoutInfo* m_meta;
    };
}
