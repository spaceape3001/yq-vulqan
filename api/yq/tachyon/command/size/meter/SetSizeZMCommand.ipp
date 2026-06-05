////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻMCommand)

namespace yq::tachyon {
    SetSizeᶻMCommand::SetSizeᶻMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeᶻMCommand::SetSizeᶻMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetSizeᶻMCommand::SetSizeᶻMCommand(const SetSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻMCommand::~SetSizeᶻMCommand()
    {
    }

    PostCPtr    SetSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻMCommand(*this, h);
    }
    
    void SetSizeᶻMCommand::init_meta()
    {
        auto w = writer<SetSizeᶻMCommand>();
        w.description("Set Size MCommand in Z");
        w.property("z", &SetSizeᶻMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
