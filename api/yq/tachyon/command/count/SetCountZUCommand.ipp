////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCountZUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCountᶻUCommand)

namespace yq::tachyon {
    SetCountᶻUCommand::SetCountᶻUCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCountᶻUCommand::SetCountᶻUCommand(const Header& h, unsigned v) : 
        CountCommand(h), m_z(v)
    {
    }

    SetCountᶻUCommand::SetCountᶻUCommand(const SetCountᶻUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetCountᶻUCommand::~SetCountᶻUCommand()
    {
    }

    PostCPtr    SetCountᶻUCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCountᶻUCommand(*this, h);
    }
    
    void SetCountᶻUCommand::init_meta()
    {
        auto w = writer<SetCountᶻUCommand>();
        w.description("Set Count Command in Z");
        w.property("z", &SetCountᶻUCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
