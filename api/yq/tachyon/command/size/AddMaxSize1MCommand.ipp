////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize¹DCommand)

namespace yq::tachyon {
    AddMaxSize¹DCommand::AddMaxSize¹DCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMaxSize¹DCommand::AddMaxSize¹DCommand(const Header& h, const Vector1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMaxSize¹DCommand::AddMaxSize¹DCommand(const AddMaxSize¹DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMaxSize¹DCommand::~AddMaxSize¹DCommand()
    {
    }
    
    PostCPtr    AddMaxSize¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize¹DCommand(*this, h);
    }

    void AddMaxSize¹DCommand::init_meta()
    {
        auto w = writer<AddMaxSize¹DCommand>();
        w.description("AddMax Size DCommand");
        w.property("Δx", &AddMaxSize¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize¹DCommand::m_Δ).tag(kTag_Save);
    }
}
