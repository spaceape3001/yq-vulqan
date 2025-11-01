////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/app/ViewerCreateCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCreateCommand)

namespace yq::tachyon {

    ViewerCreateCommand::ViewerCreateCommand(const Header&h, const ViewerCreateInfo& vci, WidgetPtr wp) : 
        AppCommand(h), m_createInfo(vci), m_widget(wp)
    {
    }

    ViewerCreateCommand::ViewerCreateCommand(const ViewerCreateCommand& cp, const Header& h) : 
        AppCommand(cp, h), m_createInfo(cp.m_createInfo), m_widget(cp.m_widget)
    {
    }
    
    ViewerCreateCommand::~ViewerCreateCommand()
    {
    }

    PostCPtr    ViewerCreateCommand::clone(rebind_k, const Header&h) const 
    {
        return new ViewerCreateCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCreateCommand::init_meta()
    {
        auto w = writer<ViewerCreateCommand>();
        w.description("ViewerCreate Command");
    }
}
