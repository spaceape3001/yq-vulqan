////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tool.hpp"
#include "ToolMetaWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tool)

namespace yq::tachyon {
    ToolMeta::ToolMeta(std::string_view name, ObjectMeta& base, const std::source_location& sl) :
        DelegateMeta(name, base, sl)
    {
        set(Flag::TOOL);
    }
    
    Tool::Tool()
    {
    }
    
    Tool::~Tool()
    {
    }
    
    void Tool::init_meta()
    {
        auto w = writer<Tool>();
        w.description("Tool base");
    }
}
