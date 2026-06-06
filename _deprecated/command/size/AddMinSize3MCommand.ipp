////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize³MCommand)

namespace yq::tachyon {
    AddMinSize³MCommand::AddMinSize³MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize³MCommand::AddMinSize³MCommand(const Header& h, const Size3M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize³MCommand::AddMinSize³MCommand(const AddMinSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize³MCommand::~AddMinSize³MCommand()
    {
    }

    PostCPtr    AddMinSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize³MCommand(*this, h);
    }
    
    void AddMinSize³MCommand::init_meta()
    {
        auto w = writer<AddMinSize³MCommand>();
        w.description("AddMin Size MCommand");
        w.property("Δx", &AddMinSize³MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize³MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize³MCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMinSize³MCommand::m_Δ).tag(kTag_Save);
    }
}
