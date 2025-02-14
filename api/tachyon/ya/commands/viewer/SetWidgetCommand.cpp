////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/viewer/SetWidgetCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yt/ui/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetWidgetCommand)

namespace yq::tachyon {

    SetWidgetCommand::SetWidgetCommand(const Header&h, WidgetPtr w) : ViewerCommand(h), m_widget(w)
    {
    }
    
    SetWidgetCommand::SetWidgetCommand(const SetWidgetCommand& cp, const Header&h) : ViewerCommand(cp, h), m_widget(cp.m_widget)
    {
    }

    SetWidgetCommand::~SetWidgetCommand()
    {
    }
        
    PostCPtr    SetWidgetCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetWidgetCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetWidgetCommand::init_info()
    {
        auto w = writer<SetWidgetCommand>();
        w.description("Viewer Widget Command");
    }
}
