////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Control.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of control information
    */
    template <typename C>
    class ControlInfo::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(ControlInfo* editorInfo) : WidgetMeta::Writer<C>(editorInfo), m_meta(editorInfo)
        {
        }
        
        Writer(ControlInfo& editorInfo) : Writer(&editorInfo)
        {
        }
        
        template <typename I>
        Writer& controls()
        {
            // TODO
            return *this;
        }
        
    private:
        ControlInfo* m_meta;
        
    };
}
