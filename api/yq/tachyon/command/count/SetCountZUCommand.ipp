////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountᶻCommand)

namespace yq::tachyon {
    SetCountᶻCommand::SetCountᶻCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountᶻCommand::SetCountᶻCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_z(v)
    {
    }

    SetCountᶻCommand::SetCountᶻCommand(const SetCountᶻCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetCountᶻCommand::~SetCountᶻCommand()
    {
    }

    PostCPtr    SetCountᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountᶻCommand(*this, h);
    }
    
    void SetCountᶻCommand::init_meta()
    {
        auto w = writer<SetCountᶻCommand>();
        w.description("Set Count Command in Z");
        w.property("z", &SetCountᶻCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
