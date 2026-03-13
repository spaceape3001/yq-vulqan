////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScale2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale²DCommand)

namespace yq::tachyon {
    AddScale²DCommand::AddScale²DCommand(const Header&h) : ScaleCommand(h)
    {
    }
    
    AddScale²DCommand::AddScale²DCommand(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }

    AddScale²DCommand::AddScale²DCommand(const AddScale²DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddScale²DCommand::~AddScale²DCommand()
    {
    }

    PostCPtr    AddScale²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScale²DCommand(*this, h);
    }
    
    void AddScale²DCommand::init_meta()
    {
        auto w = writer<AddScale²DCommand>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddScale²DCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddScale²DCommand::m_Δ).tag(kTag_Save);
    }
}
