////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeᶻCMCommand)

namespace yq::tachyon {
    SetMaxSizeᶻCMCommand::SetMaxSizeᶻCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeᶻCMCommand::SetMaxSizeᶻCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMaxSizeᶻCMCommand::SetMaxSizeᶻCMCommand(const SetMaxSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMaxSizeᶻCMCommand::~SetMaxSizeᶻCMCommand()
    {
    }

    PostCPtr    SetMaxSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeᶻCMCommand(*this, h);
    }
    
    void SetMaxSizeᶻCMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeᶻCMCommand>();
        w.description("SetMax Size CMCommand in Z");
        w.property("z", &SetMaxSizeᶻCMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
