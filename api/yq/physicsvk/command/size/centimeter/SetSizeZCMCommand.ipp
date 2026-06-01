////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻCMCommand)

namespace yq::tachyon {
    SetSizeᶻCMCommand::SetSizeᶻCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeᶻCMCommand::SetSizeᶻCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetSizeᶻCMCommand::SetSizeᶻCMCommand(const SetSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻCMCommand::~SetSizeᶻCMCommand()
    {
    }

    PostCPtr    SetSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻCMCommand(*this, h);
    }
    
    void SetSizeᶻCMCommand::init_meta()
    {
        auto w = writer<SetSizeᶻCMCommand>();
        w.description("Set Size CMCommand in Z");
        w.property("z", &SetSizeᶻCMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
