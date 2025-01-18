////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Mini.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of control information
    */
    template <typename C>
    class MiniInfo::Writer : public WidgetInfo::Writer<C> {
    public:
    
        Writer(MiniInfo* miniInfo) : WidgetInfo::Writer<C>(miniInfo), m_meta(miniInfo)
        {
        }
        
        Writer(MiniInfo& miniInfo) : Writer(&miniInfo)
        {
        }
        
        template <typename T>
        Writer& type()
        {
            // TODO
            return *this;
        }
        
    private:
        MiniInfo* m_meta;
        
    };
}

