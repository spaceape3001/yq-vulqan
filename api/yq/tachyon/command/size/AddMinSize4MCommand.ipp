////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize⁴MCommand)

namespace yq::tachyon {
    AddMinSize⁴MCommand::AddMinSize⁴MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize⁴MCommand::AddMinSize⁴MCommand(const Header& h, const Size4M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize⁴MCommand::AddMinSize⁴MCommand(const AddMinSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize⁴MCommand::~AddMinSize⁴MCommand()
    {
    }

    PostCPtr    AddMinSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize⁴MCommand(*this, h);
    }
    
    void AddMinSize⁴MCommand::init_meta()
    {
        auto w = writer<AddMinSize⁴MCommand>();
        w.description("AddMin Size MCommand");
        w.property("Δx", &AddMinSize⁴MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize⁴MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize⁴MCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMinSize⁴MCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMinSize⁴MCommand::m_Δ).tag(kTag_Save);
    }
}
