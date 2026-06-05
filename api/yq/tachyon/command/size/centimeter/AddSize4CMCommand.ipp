////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize⁴CMCommand)

namespace yq::tachyon {
    AddSize⁴CMCommand::AddSize⁴CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize⁴CMCommand::AddSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize⁴CMCommand::AddSize⁴CMCommand(const AddSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize⁴CMCommand::~AddSize⁴CMCommand()
    {
    }

    PostCPtr    AddSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize⁴CMCommand(*this, h);
    }
    
    void AddSize⁴CMCommand::init_meta()
    {
        auto w = writer<AddSize⁴CMCommand>();
        w.description("Add Size CMCommand");
        w.property("Δx", &AddSize⁴CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize⁴CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize⁴CMCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddSize⁴CMCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddSize⁴CMCommand::m_Δ).tag(kTag_Save);
    }
}
