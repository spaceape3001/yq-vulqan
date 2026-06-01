////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeᶻMCommand)

namespace yq::tachyon {
    SetMinSizeᶻMCommand::SetMinSizeᶻMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeᶻMCommand::SetMinSizeᶻMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMinSizeᶻMCommand::SetMinSizeᶻMCommand(const SetMinSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMinSizeᶻMCommand::~SetMinSizeᶻMCommand()
    {
    }

    PostCPtr    SetMinSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeᶻMCommand(*this, h);
    }
    
    void SetMinSizeᶻMCommand::init_meta()
    {
        auto w = writer<SetMinSizeᶻMCommand>();
        w.description("SetMin Size MCommand in Z");
        w.property("z", &SetMinSizeᶻMCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
