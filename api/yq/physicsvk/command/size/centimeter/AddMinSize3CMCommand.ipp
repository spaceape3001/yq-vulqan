////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSize³CMCommand)

namespace yq::tachyon {
    AddMinSize³CMCommand::AddMinSize³CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddMinSize³CMCommand::AddMinSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMinSize³CMCommand::AddMinSize³CMCommand(const AddMinSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMinSize³CMCommand::~AddMinSize³CMCommand()
    {
    }

    PostCPtr    AddMinSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSize³CMCommand(*this, h);
    }
    
    void AddMinSize³CMCommand::init_meta()
    {
        auto w = writer<AddMinSize³CMCommand>();
        w.description("AddMin Size CMCommand");
        w.property("Δx", &AddMinSize³CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddMinSize³CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddMinSize³CMCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddMinSize³CMCommand::m_Δ).tag(kTag_Save);
    }
}
