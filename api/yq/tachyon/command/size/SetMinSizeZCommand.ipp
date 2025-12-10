////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeᶻCommand)

namespace yq::tachyon {
    SetMinSizeᶻCommand::SetMinSizeᶻCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeᶻCommand::SetMinSizeᶻCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMinSizeᶻCommand::SetMinSizeᶻCommand(const SetMinSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMinSizeᶻCommand::~SetMinSizeᶻCommand()
    {
    }

    PostCPtr    SetMinSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeᶻCommand(*this, h);
    }
    
    void SetMinSizeᶻCommand::init_meta()
    {
        auto w = writer<SetMinSizeᶻCommand>();
        w.description("SetMin Size Command in Z");
        w.property("z", &SetMinSizeᶻCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
