////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Tool.hpp>
#include <0/basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tool)

namespace yq::tachyon {
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
