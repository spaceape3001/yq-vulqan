////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCount4UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCount⁴UCommand)

namespace yq::tachyon {
    AddCount⁴UCommand::AddCount⁴UCommand(const Header& h) : CountCommand(h)
    {
    }
    
    AddCount⁴UCommand::AddCount⁴UCommand(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_Δ(v)
    {
    }

    AddCount⁴UCommand::AddCount⁴UCommand(const AddCount⁴UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddCount⁴UCommand::~AddCount⁴UCommand()
    {
    }

    PostCPtr    AddCount⁴UCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCount⁴UCommand(*this, h);
    }
    
    void AddCount⁴UCommand::init_meta()
    {
        auto w = writer<AddCount⁴UCommand>();
        w.description("Add Count Command");
        w.property("Δx", &AddCount⁴UCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddCount⁴UCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddCount⁴UCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddCount⁴UCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddCount⁴UCommand::m_Δ).tag(kTag_Save);
    }
}
