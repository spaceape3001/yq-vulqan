////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WidgetStartupCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetStartupCommand)

namespace yq::tachyon {

    WidgetStartupCommand::WidgetStartupCommand(Widget* v, const Param& p) : WidgetCommand(v, p)
    {
    }
    
    WidgetStartupCommand::WidgetStartupCommand(WidgetID v, const Param& p) : WidgetCommand(v, p)
    {
    }
    
    WidgetStartupCommand::~WidgetStartupCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WidgetStartupCommand::init_info()
    {
        auto w = writer<WidgetStartupCommand>();
        w.description("Widget Startup Command");
    }
}
