////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize⁴MCommand)

namespace yq::tachyon {
    AddSize⁴MCommand::AddSize⁴MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize⁴MCommand::AddSize⁴MCommand(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize⁴MCommand::AddSize⁴MCommand(const AddSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize⁴MCommand::~AddSize⁴MCommand()
    {
    }

    PostCPtr    AddSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize⁴MCommand(*this, h);
    }
    
    void AddSize⁴MCommand::init_meta()
    {
        auto w = writer<AddSize⁴MCommand>();
        w.description("Add Size MCommand");
        w.property("Δx", &AddSize⁴MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize⁴MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize⁴MCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddSize⁴MCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddSize⁴MCommand::m_Δ).tag(kTag_Save);
    }
}
