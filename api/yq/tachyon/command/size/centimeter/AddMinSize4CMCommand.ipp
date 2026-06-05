////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize⁴CMCommand)

namespace yq::tachyon {
    AddMinSize⁴CMCommand::AddMinSize⁴CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize⁴CMCommand::AddMinSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize⁴CMCommand::AddMinSize⁴CMCommand(const AddMinSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize⁴CMCommand::~AddMinSize⁴CMCommand()
    {
    }

    PostCPtr    AddMinSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize⁴CMCommand(*this, h);
    }
    
    void AddMinSize⁴CMCommand::init_meta()
    {
        auto w = writer<AddMinSize⁴CMCommand>();
        w.description("AddMin Size CMCommand");
        w.property("Δx", &AddMinSize⁴CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize⁴CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize⁴CMCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMinSize⁴CMCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMinSize⁴CMCommand::m_Δ).tag(kTag_Save);
    }
}
