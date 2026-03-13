////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountWUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountʷUCommand)

namespace yq::tachyon {
    SetCountʷUCommand::SetCountʷUCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountʷUCommand::SetCountʷUCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_w(v)
    {
    }

    SetCountʷUCommand::SetCountʷUCommand(const SetCountʷUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetCountʷUCommand::~SetCountʷUCommand()
    {
    }

    PostCPtr    SetCountʷUCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountʷUCommand(*this, h);
    }
    
    void SetCountʷUCommand::init_meta()
    {
        auto w = writer<SetCountʷUCommand>();
        w.description("Set Count Command in X");
        w.property("w", &SetCountʷUCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
