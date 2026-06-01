////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize²MCommand)

namespace yq::tachyon {
    AddMinSize²MCommand::AddMinSize²MCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMinSize²MCommand::AddMinSize²MCommand(const Header& h, const Size2M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize²MCommand::AddMinSize²MCommand(const AddMinSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize²MCommand::~AddMinSize²MCommand()
    {
    }

    PostCPtr    AddMinSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize²MCommand(*this, h);
    }
    
    void AddMinSize²MCommand::init_meta()
    {
        auto w = writer<AddMinSize²MCommand>();
        w.description("AddMin Size MCommand");
        w.property("Δx", &AddMinSize²MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize²MCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMinSize²MCommand::m_Δ).tag(kTag_Save);
    }
}
