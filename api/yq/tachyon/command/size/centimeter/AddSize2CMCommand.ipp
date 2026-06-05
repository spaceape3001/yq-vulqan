////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize²CMCommand)

namespace yq::tachyon {
    AddSize²CMCommand::AddSize²CMCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddSize²CMCommand::AddSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize²CMCommand::AddSize²CMCommand(const AddSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize²CMCommand::~AddSize²CMCommand()
    {
    }

    PostCPtr    AddSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize²CMCommand(*this, h);
    }
    
    void AddSize²CMCommand::init_meta()
    {
        auto w = writer<AddSize²CMCommand>();
        w.description("Add Size CMCommand");
        w.property("Δx", &AddSize²CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize²CMCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddSize²CMCommand::m_Δ).tag(kTag_Save);
    }
}
