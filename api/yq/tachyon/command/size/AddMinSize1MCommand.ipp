////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize¹MCommand)

namespace yq::tachyon {
    AddMinSize¹MCommand::AddMinSize¹MCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMinSize¹MCommand::AddMinSize¹MCommand(const Header& h, const Size1D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMinSize¹MCommand::AddMinSize¹MCommand(const AddMinSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMinSize¹MCommand::~AddMinSize¹MCommand()
    {
    }
    
    PostCPtr    AddMinSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize¹MCommand(*this, h);
    }

    void AddMinSize¹MCommand::init_meta()
    {
        auto w = writer<AddMinSize¹MCommand>();
        w.description("AddMin Size MCommand");
        w.property("Δx", &AddMinSize¹MCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMinSize¹MCommand::m_Δ).tag(kTag_Save);
    }
}
