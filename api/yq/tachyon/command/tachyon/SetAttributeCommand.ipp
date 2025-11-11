////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/tachyon/SetAttributeCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAttributeCommand)

namespace yq::tachyon {

    SetAttributeCommand::SetAttributeCommand(const Header&h, key_spec_t k, const Any&v) : TachyonCommand(h), m_key(k), m_value(v)
    {
    }
    
    SetAttributeCommand::SetAttributeCommand(const Header&h, key_spec_t k, Any&&v) : TachyonCommand(h), m_key(k), m_value(std::move(v))
    {
    }
    
    SetAttributeCommand::SetAttributeCommand(const SetAttributeCommand& cp, const Header& h) : 
        TachyonCommand(cp, h), m_key(cp.m_key), m_value(cp.m_value)
    {
    }
    
    SetAttributeCommand::~SetAttributeCommand()
    {
    }

    PostCPtr    SetAttributeCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetAttributeCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetAttributeCommand::init_meta()
    {
        auto w = writer<SetAttributeCommand>();
        w.description("Set Attribute Command");
    }
}
