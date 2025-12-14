////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetColorProfileUrlCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetColorProfileUrlCommand)

namespace yq::tachyon {

    SetColorProfileUrlCommand::SetColorProfileUrlCommand(const Header&h, const Url& dm) : ColorProfileCommand(h), m_url(dm)
    {
    }

    SetColorProfileUrlCommand::SetColorProfileUrlCommand(const SetColorProfileUrlCommand& cp, const Header& h) : 
        ColorProfileCommand(cp, h), m_url(cp.m_url)
    {
    }
    
    SetColorProfileUrlCommand::~SetColorProfileUrlCommand()
    {
    }

    PostCPtr    SetColorProfileUrlCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetColorProfileUrlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetColorProfileUrlCommand::init_meta()
    {
        auto w = writer<SetColorProfileUrlCommand>();
        w.description("Set ColorProfile Url Command");
        w.property("url", &SetColorProfileUrlCommand::m_url);
    }
}
