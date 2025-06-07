////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSizeZCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeᶻCommand)

namespace yq::tachyon {
    SetMaxSizeᶻCommand::SetMaxSizeᶻCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeᶻCommand::SetMaxSizeᶻCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetMaxSizeᶻCommand::SetMaxSizeᶻCommand(const SetMaxSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetMaxSizeᶻCommand::~SetMaxSizeᶻCommand()
    {
    }

    PostCPtr    SetMaxSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeᶻCommand(*this, h);
    }
    
    void SetMaxSizeᶻCommand::init_info()
    {
        auto w = writer<SetMaxSizeᶻCommand>();
        w.description("SetMax Size Command in Z");
        w.property("z", &SetMaxSizeᶻCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
