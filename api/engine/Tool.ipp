////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Tool.hpp"
#include <basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::engine::Tool)

namespace yq {
    namespace engine {
        
        ToolInfo::ToolInfo(std::string_view name, MetaObjectInfo& base, const std::source_location& sl) :
            MetaObjectInfo(name, base, sl)
        {
        }
        
        Tool::Tool()
        {
        }
        
        Tool::~Tool()
        {
        }
        
        
        YQ_INVOKE(
            [[maybe_unused]] auto manip = writer<Tool>();
        )
    
    }
}
