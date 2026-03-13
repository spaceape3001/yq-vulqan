////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddScale1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddScale¹DCommand)

namespace yq::tachyon {
    AddScale¹DCommand::AddScale¹DCommand(const Header& h) : ScaleCommand(h)
    {
    }

    AddScale¹DCommand::AddScale¹DCommand(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_Δ(v)
    {
    }
    
    AddScale¹DCommand::AddScale¹DCommand(const AddScale¹DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddScale¹DCommand::~AddScale¹DCommand()
    {
    }
    
    PostCPtr    AddScale¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddScale¹DCommand(*this, h);
    }

    void AddScale¹DCommand::init_meta()
    {
        auto w = writer<AddScale¹DCommand>();
        w.description("Add Scale Command");
        w.property("Δx", &AddScale¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddScale¹DCommand::m_Δ).tag(kTag_Save);
    }
}
