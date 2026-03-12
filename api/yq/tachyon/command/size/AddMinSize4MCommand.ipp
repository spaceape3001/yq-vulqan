////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize⁴DCommand)

namespace yq::tachyon {
    AddMinSize⁴DCommand::AddMinSize⁴DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize⁴DCommand::AddMinSize⁴DCommand(const Header& h, const Vector4D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize⁴DCommand::AddMinSize⁴DCommand(const AddMinSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize⁴DCommand::~AddMinSize⁴DCommand()
    {
    }

    PostCPtr    AddMinSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize⁴DCommand(*this, h);
    }
    
    void AddMinSize⁴DCommand::init_meta()
    {
        auto w = writer<AddMinSize⁴DCommand>();
        w.description("AddMin Size DCommand");
        w.property("Δx", &AddMinSize⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δw", &AddMinSize⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δ",  &AddMinSize⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
