////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize³DCommand)

namespace yq::tachyon {
    AddMinSize³DCommand::AddMinSize³DCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize³DCommand::AddMinSize³DCommand(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize³DCommand::AddMinSize³DCommand(const AddMinSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize³DCommand::~AddMinSize³DCommand()
    {
    }

    PostCPtr    AddMinSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize³DCommand(*this, h);
    }
    
    void AddMinSize³DCommand::init_meta()
    {
        auto w = writer<AddMinSize³DCommand>();
        w.description("AddMin Size DCommand");
        w.property("Δx", &AddMinSize³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize³DCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMinSize³DCommand::m_Δ).tag(kTag_Save);
    }
}
