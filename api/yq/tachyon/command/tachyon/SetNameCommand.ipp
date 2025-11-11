////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/tachyon/SetNameCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetNameCommand)

namespace yq::tachyon {

    SetNameCommand::SetNameCommand(const Header&h, std::string&& k) : TachyonCommand(h), m_name(std::move(k))
    {
    
    }
    
    SetNameCommand::SetNameCommand(const Header&h, std::string_view k) : TachyonCommand(h), m_name(k)
    {
    }

    SetNameCommand::SetNameCommand(const SetNameCommand& cp, const Header& h) : 
        TachyonCommand(cp, h), m_name(cp.m_name)
    {
    }
    
    SetNameCommand::~SetNameCommand()
    {
    }

    PostCPtr    SetNameCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetNameCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetNameCommand::init_meta()
    {
        auto w = writer<SetNameCommand>();
        w.description("SetName Command");
        w.property("name", &SetNameCommand::m_name).tag(kTag_Save);
    }
}
