////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize²MCommand)

namespace yq::tachyon {
    AddSize²MCommand::AddSize²MCommand(const Header&h) : SizeCommand(h)
    {
    }
    
    AddSize²MCommand::AddSize²MCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize²MCommand::AddSize²MCommand(const AddSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize²MCommand::~AddSize²MCommand()
    {
    }

    PostCPtr    AddSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize²MCommand(*this, h);
    }
    
    void AddSize²MCommand::init_meta()
    {
        auto w = writer<AddSize²MCommand>();
        w.description("Add Size MCommand");
        w.property("Δx", &AddSize²MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize²MCommand::Δy).tag(kTag_Log);
        w.property("Δ",  &AddSize²MCommand::m_Δ).tag(kTag_Save);
    }
}
