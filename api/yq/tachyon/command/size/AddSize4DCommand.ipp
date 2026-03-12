////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize⁴DCommand)

namespace yq::tachyon {
    AddSize⁴DCommand::AddSize⁴DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize⁴DCommand::AddSize⁴DCommand(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize⁴DCommand::AddSize⁴DCommand(const AddSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize⁴DCommand::~AddSize⁴DCommand()
    {
    }

    PostCPtr    AddSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize⁴DCommand(*this, h);
    }
    
    void AddSize⁴DCommand::init_meta()
    {
        auto w = writer<AddSize⁴DCommand>();
        w.description("Add Size DCommand");
        w.property("Δx", &AddSize⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddSize⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddSize⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
