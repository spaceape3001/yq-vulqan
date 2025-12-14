////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetColorProfileSpecCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetColorProfileSpecCommand)

namespace yq::tachyon {

    SetColorProfileSpecCommand::SetColorProfileSpecCommand(const Header&h, const std::string& dm) : ColorProfileCommand(h), m_spec(dm)
    {
    }

    SetColorProfileSpecCommand::SetColorProfileSpecCommand(const SetColorProfileSpecCommand& cp, const Header& h) : 
        ColorProfileCommand(cp, h), m_spec(cp.m_spec)
    {
    }
    
    SetColorProfileSpecCommand::~SetColorProfileSpecCommand()
    {
    }

    PostCPtr    SetColorProfileSpecCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetColorProfileSpecCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetColorProfileSpecCommand::init_meta()
    {
        auto w = writer<SetColorProfileSpecCommand>();
        w.description("Set Height Field Spec Command");
        w.property("spec", &SetColorProfileSpecCommand::m_spec);
    }
}
