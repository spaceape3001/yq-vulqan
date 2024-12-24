////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WidgetCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetCommand)

namespace yq::tachyon {
    WidgetCommandInfo::WidgetCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WidgetCommand::WidgetCommand(const Widget* v, const Param& p) : Command(p), WidgetBind(v)
    {
    }
    
    WidgetCommand::WidgetCommand(WidgetID v, const Param& p) : Command(p), WidgetBind(v)
    {
    }

    WidgetCommand::~WidgetCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WidgetCommand::init_info()
    {
        auto w = writer<WidgetCommand>();
        w.description("Widget command base class");
    }
}
