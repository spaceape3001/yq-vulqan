////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountᶻCommand)

namespace yq::tachyon {
    AddCountᶻCommand::AddCountᶻCommand(const Header&h) : 
        CountCommand(h)
    {
    }
    
    AddCountᶻCommand::AddCountᶻCommand(const Header&h, unsigned z) : 
        CountCommand(h), m_Δz(z)
    {
    }

    AddCountᶻCommand::AddCountᶻCommand(const AddCountᶻCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddCountᶻCommand::~AddCountᶻCommand()
    {
    }

    PostCPtr    AddCountᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountᶻCommand(*this, h);
    }
    
    void AddCountᶻCommand::init_meta()
    {
        auto w = writer<AddCountᶻCommand>();
        w.description("Add Count Command in Z");
        w.property("Δz", &AddCountᶻCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
