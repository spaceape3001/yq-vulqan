////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WidgetCommand.hpp>

#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WidgetCommand)

namespace yq::tachyon {
    WidgetCommand::WidgetCommand(const Header&h) : Command(h)
    {
    }
    
    WidgetCommand::WidgetCommand(const WidgetCommand& cp, const Header&h) : Command(cp, h)
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
