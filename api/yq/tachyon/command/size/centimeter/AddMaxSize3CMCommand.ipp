////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³CMCommand)

namespace yq::tachyon {
    AddMaxSize³CMCommand::AddMaxSize³CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize³CMCommand::AddMaxSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³CMCommand::AddMaxSize³CMCommand(const AddMaxSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³CMCommand::~AddMaxSize³CMCommand()
    {
    }

    PostCPtr    AddMaxSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³CMCommand(*this, h);
    }
    
    void AddMaxSize³CMCommand::init_meta()
    {
        auto w = writer<AddMaxSize³CMCommand>();
        w.description("AddMax Size CMCommand");
        w.property("Δx", &AddMaxSize³CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³CMCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³CMCommand::m_Δ).tag(kTag_Save);
    }
}
