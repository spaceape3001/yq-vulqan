////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize¹CMCommand)

namespace yq::tachyon {
    AddMinSize¹CMCommand::AddMinSize¹CMCommand(const Header& h) : SizeCommand(h)
    {
    }

    AddMinSize¹CMCommand::AddMinSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }
    
    AddMinSize¹CMCommand::AddMinSize¹CMCommand(const AddMinSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddMinSize¹CMCommand::~AddMinSize¹CMCommand()
    {
    }
    
    PostCPtr    AddMinSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize¹CMCommand(*this, h);
    }

    void AddMinSize¹CMCommand::init_meta()
    {
        auto w = writer<AddMinSize¹CMCommand>();
        w.description("AddMin Size CMCommand");
        w.property("Δx", &AddMinSize¹CMCommand::Δx).tag(kTag_Log);
        w.property("Δ",  &AddMinSize¹CMCommand::m_Δ).tag(kTag_Save);
    }
}
