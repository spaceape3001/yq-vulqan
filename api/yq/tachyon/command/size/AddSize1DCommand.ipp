////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize¹DCommand)

namespace yq::tachyon {
    AddSize¹DCommand::AddSize¹DCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddSize¹DCommand::AddSize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddSize¹DCommand::AddSize¹DCommand(const AddSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddSize¹DCommand::~AddSize¹DCommand()
    {
    }
    
    PostCPtr    AddSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize¹DCommand(*this, h);
    }

    void AddSize¹DCommand::init_meta()
    {
        auto w = writer<AddSize¹DCommand>();
        w.description("Add Size DCommand");
        w.property("Δx", &AddSize¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddSize¹DCommand::m_Δ).tag(kTag_Save);
    }
}
