////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountʷCommand)

namespace yq::tachyon {
    SetCountʷCommand::SetCountʷCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountʷCommand::SetCountʷCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_w(v)
    {
    }

    SetCountʷCommand::SetCountʷCommand(const SetCountʷCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetCountʷCommand::~SetCountʷCommand()
    {
    }

    PostCPtr    SetCountʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountʷCommand(*this, h);
    }
    
    void SetCountʷCommand::init_meta()
    {
        auto w = writer<SetCountʷCommand>();
        w.description("Set Count Command in X");
        w.property("w", &SetCountʷCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
