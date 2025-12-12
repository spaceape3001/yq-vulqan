////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTextureUrlCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTextureUrlCommand)

namespace yq::tachyon {

    SetTextureUrlCommand::SetTextureUrlCommand(const Header&h, const Url& dm) : Command(h), m_url(dm)
    {
    }

    SetTextureUrlCommand::SetTextureUrlCommand(const SetTextureUrlCommand& cp, const Header& h) : 
        Command(cp, h), m_url(cp.m_url)
    {
    }
    
    SetTextureUrlCommand::~SetTextureUrlCommand()
    {
    }

    PostCPtr    SetTextureUrlCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetTextureUrlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetTextureUrlCommand::init_meta()
    {
        auto w = writer<SetTextureUrlCommand>();
        w.description("Set Texture Url Command");
        w.property("url", &SetTextureUrlCommand::m_url);
    }
}
