////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻDCommand)

namespace yq::tachyon {
    SetSizeᶻDCommand::SetSizeᶻDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeᶻDCommand::SetSizeᶻDCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetSizeᶻDCommand::SetSizeᶻDCommand(const SetSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻDCommand::~SetSizeᶻDCommand()
    {
    }

    PostCPtr    SetSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻDCommand(*this, h);
    }
    
    void SetSizeᶻDCommand::init_meta()
    {
        auto w = writer<SetSizeᶻDCommand>();
        w.description("Set Size DCommand in Z");
        w.property("z", &SetSizeᶻDCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
