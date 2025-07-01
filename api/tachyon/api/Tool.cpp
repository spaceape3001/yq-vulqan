////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Tool.hpp>
#include <tachyon/api/ToolMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tool)

namespace yq::tachyon {
    ToolMeta::ToolMeta(std::string_view name, ObjectInfo& base, const std::source_location& sl) :
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
    
    void Tool::init_info()
    {
        auto w = writer<Tool>();
        w.description("Tool base");
    }
}
