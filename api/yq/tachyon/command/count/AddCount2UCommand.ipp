////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount2UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount²UCommand)

namespace yq::tachyon {
    AddCount²UCommand::AddCount²UCommand(const Header&h) : CountCommand(h)
    {
    }
    
    AddCount²UCommand::AddCount²UCommand(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount²UCommand::AddCount²UCommand(const AddCount²UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount²UCommand::~AddCount²UCommand()
    {
    }

    PostCPtr    AddCount²UCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCount²UCommand(*this, h);
    }
    
    void AddCount²UCommand::init_meta()
    {
        auto w = writer<AddCount²UCommand>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount²UCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount²UCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddCount²UCommand::m_Δ).tag(kTag_Save);
    }
}
