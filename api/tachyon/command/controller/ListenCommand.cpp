////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/controller/ListenCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ListenCommand)

namespace yq::tachyon {

    ListenCommand::ListenCommand(const Header& h, TypedID t) : 
        ControllerCommand(h), m_tachyon(t)
    {
    }
    
    ListenCommand::ListenCommand(const ListenCommand& cp, const Header& h) : 
        ControllerCommand(cp, h), m_tachyon(cp.m_tachyon)
    {
    }
    
    ListenCommand::~ListenCommand()
    {
    }
    
    PostCPtr    ListenCommand::clone(rebind_k, const Header& h) const
    {
        return new ListenCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void ListenCommand::init_meta()
    {
        auto w = writer<ListenCommand>();
        w.description("Listen Command");
    }
}
