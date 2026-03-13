////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScale4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale⁴DCommand)

namespace yq::tachyon {
    AddScale⁴DCommand::AddScale⁴DCommand(const Header& h) : ScaleCommand(h)
    {
    }
    
    AddScale⁴DCommand::AddScale⁴DCommand(const Header& h, const Vector4D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale⁴DCommand::AddScale⁴DCommand(const AddScale⁴DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale⁴DCommand::~AddScale⁴DCommand()
    {
    }

    PostCPtr    AddScale⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScale⁴DCommand(*this, h);
    }
    
    void AddScale⁴DCommand::init_meta()
    {
        auto w = writer<AddScale⁴DCommand>();
        w.description("Add Scale Command");
        w.property("Δw", &AddScale⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δx", &AddScale⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddScale⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddScale⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
