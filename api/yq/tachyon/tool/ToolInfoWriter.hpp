////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tool/Tool.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class ToolInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(ToolInfo* manipInfo) : ObjectInfo::Writer<C>(manipInfo)
        {
        }
        
        Writer(ToolInfo& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
