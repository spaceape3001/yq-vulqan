////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize²CMCommand)

namespace yq::tachyon {
    AddMaxSize²CMCommand::AddMaxSize²CMCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMaxSize²CMCommand::AddMaxSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize²CMCommand::AddMaxSize²CMCommand(const AddMaxSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize²CMCommand::~AddMaxSize²CMCommand()
    {
    }

    PostCPtr    AddMaxSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize²CMCommand(*this, h);
    }
    
    void AddMaxSize²CMCommand::init_meta()
    {
        auto w = writer<AddMaxSize²CMCommand>();
        w.description("AddMax Size CMCommand");
        w.property("Δx", &AddMaxSize²CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize²CMCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize²CMCommand::m_Δ).tag(kTag_Save);
    }
}
