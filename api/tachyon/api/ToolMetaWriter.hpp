////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tool.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ToolMeta::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(ToolMeta* manipInfo) : ObjectInfo::Writer<C>(manipInfo)
        {
        }
        
        Writer(ToolMeta& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
