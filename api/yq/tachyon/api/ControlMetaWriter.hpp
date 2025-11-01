////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Control.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of control information
    */
    template <typename C>
    class ControlMeta::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(ControlMeta* editorInfo) : WidgetMeta::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(ControlMeta& editorInfo) : Writer(&editorInfo)
        {
        }
        
        template <typename I>
        Writer& controls()
        {
            // TODO
            return *this;
        }
        
    private:
        ControlMeta* m_meta;
        
    };
}
