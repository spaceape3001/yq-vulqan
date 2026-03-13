////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScale3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale³DCommand)

namespace yq::tachyon {
    AddScale³DCommand::AddScale³DCommand(const Header& h) : ScaleCommand(h)
    {
    }
    
    AddScale³DCommand::AddScale³DCommand(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale³DCommand::AddScale³DCommand(const AddScale³DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale³DCommand::~AddScale³DCommand()
    {
    }

    PostCPtr    AddScale³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScale³DCommand(*this, h);
    }
    
    void AddScale³DCommand::init_meta()
    {
        auto w = writer<AddScale³DCommand>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddScale³DCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddScale³DCommand::m_Δ).tag(kTag_Save);
    }
}
