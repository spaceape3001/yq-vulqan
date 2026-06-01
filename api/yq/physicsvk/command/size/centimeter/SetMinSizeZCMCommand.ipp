////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeᶻCMCommand)

namespace yq::tachyon {
    SetMinSizeᶻCMCommand::SetMinSizeᶻCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeᶻCMCommand::SetMinSizeᶻCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMinSizeᶻCMCommand::SetMinSizeᶻCMCommand(const SetMinSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMinSizeᶻCMCommand::~SetMinSizeᶻCMCommand()
    {
    }

    PostCPtr    SetMinSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeᶻCMCommand(*this, h);
    }
    
    void SetMinSizeᶻCMCommand::init_meta()
    {
        auto w = writer<SetMinSizeᶻCMCommand>();
        w.description("SetMin Size CMCommand in Z");
        w.property("z", &SetMinSizeᶻCMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
