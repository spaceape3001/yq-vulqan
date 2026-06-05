////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize⁴CMCommand)

namespace yq::tachyon {
    AddMaxSize⁴CMCommand::AddMaxSize⁴CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize⁴CMCommand::AddMaxSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize⁴CMCommand::AddMaxSize⁴CMCommand(const AddMaxSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize⁴CMCommand::~AddMaxSize⁴CMCommand()
    {
    }

    PostCPtr    AddMaxSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize⁴CMCommand(*this, h);
    }
    
    void AddMaxSize⁴CMCommand::init_meta()
    {
        auto w = writer<AddMaxSize⁴CMCommand>();
        w.description("AddMax Size CMCommand");
        w.property("Δx", &AddMaxSize⁴CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize⁴CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize⁴CMCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMaxSize⁴CMCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize⁴CMCommand::m_Δ).tag(kTag_Save);
    }
}
