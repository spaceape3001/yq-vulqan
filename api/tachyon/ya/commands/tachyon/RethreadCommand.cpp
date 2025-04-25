////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/tachyon/RethreadCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RethreadCommand)

namespace yq::tachyon {
    RethreadCommand::RethreadCommand(const Header&h, ThreadID th) : 
        TachyonCommand(h), m_thread(th)
    {
    }

    RethreadCommand::RethreadCommand(const RethreadCommand& cp, const Header&h) : 
        TachyonCommand(cp,h), m_thread(cp.m_thread)
    {
    }

    RethreadCommand::~RethreadCommand()
    {
    }

    PostCPtr    RethreadCommand::clone(rebind_k, const Header& h) const 
    {
        return new RethreadCommand(*this, h);
    }
    
    void RethreadCommand::init_info()
    {
        auto w = writer<RethreadCommand>();
        w.description("Rethread Command");
    }
}
