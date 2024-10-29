////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tool.hpp"
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tool)

namespace yq::tachyon {
    ToolInfo::ToolInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(name, base, sl)
    {
        set(Flag::TOOL);
    }
    
    Tool::Tool()
    {
    }
    
    Tool::~Tool()
    {
    }
    
    static void reg_tool()
    {
        auto w = writer<Tool>();
        w.description("Tool base");
    }
    
    YQ_INVOKE(reg_tool();)
}
