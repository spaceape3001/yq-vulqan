////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeᶻDCommand)

namespace yq::tachyon {
    SetMinSizeᶻDCommand::SetMinSizeᶻDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeᶻDCommand::SetMinSizeᶻDCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMinSizeᶻDCommand::SetMinSizeᶻDCommand(const SetMinSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMinSizeᶻDCommand::~SetMinSizeᶻDCommand()
    {
    }

    PostCPtr    SetMinSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeᶻDCommand(*this, h);
    }
    
    void SetMinSizeᶻDCommand::init_meta()
    {
        auto w = writer<SetMinSizeᶻDCommand>();
        w.description("SetMin Size DCommand in Z");
        w.property("z", &SetMinSizeᶻDCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
