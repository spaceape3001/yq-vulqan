////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize³MCommand)

namespace yq::tachyon {
    AddMaxSize³MCommand::AddMaxSize³MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMaxSize³MCommand::AddMaxSize³MCommand(const Header& h, const Size3M& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize³MCommand::AddMaxSize³MCommand(const AddMaxSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize³MCommand::~AddMaxSize³MCommand()
    {
    }

    PostCPtr    AddMaxSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize³MCommand(*this, h);
    }
    
    void AddMaxSize³MCommand::init_meta()
    {
        auto w = writer<AddMaxSize³MCommand>();
        w.description("AddMax Size MCommand");
        w.property("Δx", &AddMaxSize³MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize³MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMaxSize³MCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize³MCommand::m_Δ).tag(kTag_Save);
    }
}
