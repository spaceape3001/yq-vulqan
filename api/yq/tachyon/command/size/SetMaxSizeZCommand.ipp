////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeᶻDCommand)

namespace yq::tachyon {
    SetMaxSizeᶻDCommand::SetMaxSizeᶻDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeᶻDCommand::SetMaxSizeᶻDCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMaxSizeᶻDCommand::SetMaxSizeᶻDCommand(const SetMaxSizeᶻDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMaxSizeᶻDCommand::~SetMaxSizeᶻDCommand()
    {
    }

    PostCPtr    SetMaxSizeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeᶻDCommand(*this, h);
    }
    
    void SetMaxSizeᶻDCommand::init_meta()
    {
        auto w = writer<SetMaxSizeᶻDCommand>();
        w.description("SetMax Size DCommand in Z");
        w.property("z", &SetMaxSizeᶻDCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
