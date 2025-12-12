////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetHeightFieldUrlCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeightFieldUrlCommand)

namespace yq::tachyon {

    SetHeightFieldUrlCommand::SetHeightFieldUrlCommand(const Header&h, const Url& dm) : Command(h), m_url(dm)
    {
    }

    SetHeightFieldUrlCommand::SetHeightFieldUrlCommand(const SetHeightFieldUrlCommand& cp, const Header& h) : 
        Command(cp, h), m_url(cp.m_url)
    {
    }
    
    SetHeightFieldUrlCommand::~SetHeightFieldUrlCommand()
    {
    }

    PostCPtr    SetHeightFieldUrlCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetHeightFieldUrlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetHeightFieldUrlCommand::init_meta()
    {
        auto w = writer<SetHeightFieldUrlCommand>();
        w.description("Set Height Field Url Command");
        w.property("url", &SetHeightFieldUrlCommand::m_url);
    }
}
