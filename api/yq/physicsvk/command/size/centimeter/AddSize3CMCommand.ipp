////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize³CMCommand)

namespace yq::tachyon {
    AddSize³CMCommand::AddSize³CMCommand(const Header& h) : SizeCommand(h)
    {
    }
    
    AddSize³CMCommand::AddSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize³CMCommand::AddSize³CMCommand(const AddSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize³CMCommand::~AddSize³CMCommand()
    {
    }

    PostCPtr    AddSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSize³CMCommand(*this, h);
    }
    
    void AddSize³CMCommand::init_meta()
    {
        auto w = writer<AddSize³CMCommand>();
        w.description("Add Size CMCommand");
        w.property("Δx", &AddSize³CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize³CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddSize³CMCommand::Δz).tag(kTag_Log);
        w.property("Δ",  &AddSize³CMCommand::m_Δ).tag(kTag_Save);
    }
}
