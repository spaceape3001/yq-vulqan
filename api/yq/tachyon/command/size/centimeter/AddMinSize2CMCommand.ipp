////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize²CMCommand)

namespace yq::tachyon {
    AddMinSize²CMCommand::AddMinSize²CMCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMinSize²CMCommand::AddMinSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize²CMCommand::AddMinSize²CMCommand(const AddMinSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize²CMCommand::~AddMinSize²CMCommand()
    {
    }

    PostCPtr    AddMinSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize²CMCommand(*this, h);
    }
    
    void AddMinSize²CMCommand::init_meta()
    {
        auto w = writer<AddMinSize²CMCommand>();
        w.description("AddMin Size CMCommand");
        w.property("Δx", &AddMinSize²CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize²CMCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMinSize²CMCommand::m_Δ).tag(kTag_Save);
    }
}
