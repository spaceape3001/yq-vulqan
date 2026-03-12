////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeᶻMCommand)

namespace yq::tachyon {
    SetMaxSizeᶻMCommand::SetMaxSizeᶻMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeᶻMCommand::SetMaxSizeᶻMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMaxSizeᶻMCommand::SetMaxSizeᶻMCommand(const SetMaxSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMaxSizeᶻMCommand::~SetMaxSizeᶻMCommand()
    {
    }

    PostCPtr    SetMaxSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeᶻMCommand(*this, h);
    }
    
    void SetMaxSizeᶻMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeᶻMCommand>();
        w.description("SetMax Size MCommand in Z");
        w.property("z", &SetMaxSizeᶻMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
