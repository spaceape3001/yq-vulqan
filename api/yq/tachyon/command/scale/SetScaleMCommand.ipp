////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleMCommand)

namespace yq::tachyon {
    SetScaleMCommand::SetScaleMCommand(const Header& h, const Meter& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }
    
    SetScaleMCommand::SetScaleMCommand(const SetScaleMCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }

    SetScaleMCommand::~SetScaleMCommand()
    {
    }
    
    PostCPtr    SetScaleMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleMCommand(*this, h);
    }

    void SetScaleMCommand::init_meta()
    {
        auto w = writer<SetScaleMCommand>();
        w.description("Set Scale Command");
        w.property("scale", &SetScaleMCommand::m_scale).tag(kTag_Save).tag(kTag_Log);
    }
}
