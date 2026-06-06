////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize⁴MCommand)

namespace yq::tachyon {
    AddMaxSize⁴MCommand::AddMaxSize⁴MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize⁴MCommand::AddMaxSize⁴MCommand(const Header& h, const Size4M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize⁴MCommand::AddMaxSize⁴MCommand(const AddMaxSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize⁴MCommand::~AddMaxSize⁴MCommand()
    {
    }

    PostCPtr    AddMaxSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize⁴MCommand(*this, h);
    }
    
    void AddMaxSize⁴MCommand::init_meta()
    {
        auto w = writer<AddMaxSize⁴MCommand>();
        w.description("AddMax Size MCommand");
        w.property("Δx", &AddMaxSize⁴MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize⁴MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize⁴MCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMaxSize⁴MCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize⁴MCommand::m_Δ).tag(kTag_Save);
    }
}
