////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize¹DCommand)

namespace yq::tachyon {
    AddMinSize¹DCommand::AddMinSize¹DCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMinSize¹DCommand::AddMinSize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMinSize¹DCommand::AddMinSize¹DCommand(const AddMinSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMinSize¹DCommand::~AddMinSize¹DCommand()
    {
    }
    
    PostCPtr    AddMinSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize¹DCommand(*this, h);
    }

    void AddMinSize¹DCommand::init_meta()
    {
        auto w = writer<AddMinSize¹DCommand>();
        w.description("AddMin Size DCommand");
        w.property("Δx", &AddMinSize¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMinSize¹DCommand::m_Δ).tag(kTag_Save);
    }
}
