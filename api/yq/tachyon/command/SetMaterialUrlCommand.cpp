////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaterialUrlCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaterialUrlCommand)

namespace yq::tachyon {

    SetMaterialUrlCommand::SetMaterialUrlCommand(const Header&h, const Url& dm) : Command(h), m_url(dm)
    {
    }

    SetMaterialUrlCommand::SetMaterialUrlCommand(const SetMaterialUrlCommand& cp, const Header& h) : 
        Command(cp, h), m_url(cp.m_url)
    {
    }
    
    SetMaterialUrlCommand::~SetMaterialUrlCommand()
    {
    }

    PostCPtr    SetMaterialUrlCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaterialUrlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMaterialUrlCommand::init_meta()
    {
        auto w = writer<SetMaterialUrlCommand>();
        w.description("Set Material Url Command");
        w.property("url", &SetMaterialUrlCommand::m_url);
    }
}
