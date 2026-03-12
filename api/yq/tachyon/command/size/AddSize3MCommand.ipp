////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize³MCommand)

namespace yq::tachyon {
    AddSize³MCommand::AddSize³MCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize³MCommand::AddSize³MCommand(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize³MCommand::AddSize³MCommand(const AddSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize³MCommand::~AddSize³MCommand()
    {
    }

    PostCPtr    AddSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize³MCommand(*this, h);
    }
    
    void AddSize³MCommand::init_meta()
    {
        auto w = writer<AddSize³MCommand>();
        w.description("Add Size MCommand");
        w.property("Δx", &AddSize³MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize³MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize³MCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddSize³MCommand::m_Δ).tag(kTag_Save);
    }
}
