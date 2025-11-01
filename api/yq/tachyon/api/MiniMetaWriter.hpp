////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Mini.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of control information
    */
    template <typename C>
    class MiniMeta::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(MiniMeta* miniInfo) : WidgetMeta::Writer<C>(miniInfo), m_meta(miniInfo)
        {
        }
        
        Writer(MiniMeta& miniInfo) : Writer(&miniInfo)
        {
        }
        
        template <typename T>
        Writer& type()
        {
            // TODO
            return *this;
        }
        
    private:
        MiniMeta* m_meta;
        
    };
}

