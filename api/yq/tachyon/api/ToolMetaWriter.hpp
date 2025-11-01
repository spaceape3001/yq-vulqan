////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tool.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ToolMeta::Writer : public ObjectMeta::Writer<C> {
    public:
        Writer(ToolMeta* manipInfo) : ObjectMeta::Writer<C>(manipInfo)
        {
        }
        
        Writer(ToolMeta& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
