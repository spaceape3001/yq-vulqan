////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/SetSizeZCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeᶻCommand)

namespace yq::tachyon {
    SetSizeᶻCommand::SetSizeᶻCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeᶻCommand::SetSizeᶻCommand(const Header& h, double v) : 
        SizeCommand(h), m_z(v)
    {
    }

    SetSizeᶻCommand::SetSizeᶻCommand(const SetSizeᶻCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetSizeᶻCommand::~SetSizeᶻCommand()
    {
    }

    PostCPtr    SetSizeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeᶻCommand(*this, h);
    }
    
    void SetSizeᶻCommand::init_meta()
    {
        auto w = writer<SetSizeᶻCommand>();
        w.description("Set Size Command in Z");
        w.property("z", &SetSizeᶻCommand::m_z).tag(kTag_Log).tag(kTag_Save);
    }
}
