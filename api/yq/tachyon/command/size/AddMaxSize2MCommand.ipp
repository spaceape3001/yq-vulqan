////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize²MCommand)

namespace yq::tachyon {
    AddMaxSize²MCommand::AddMaxSize²MCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMaxSize²MCommand::AddMaxSize²MCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize²MCommand::AddMaxSize²MCommand(const AddMaxSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize²MCommand::~AddMaxSize²MCommand()
    {
    }

    PostCPtr    AddMaxSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize²MCommand(*this, h);
    }
    
    void AddMaxSize²MCommand::init_meta()
    {
        auto w = writer<AddMaxSize²MCommand>();
        w.description("AddMax Size MCommand");
        w.property("Δx", &AddMaxSize²MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize²MCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize²MCommand::m_Δ).tag(kTag_Save);
    }
}
