////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Tool.hpp>
#include <yq/tachyon/api/ToolMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tool)

namespace yq::tachyon {
    ToolMeta::ToolMeta(std::string_view name, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(name, base, sl)
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
