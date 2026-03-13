////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddCountZUCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddCountᶻUCommand)

namespace yq::tachyon {
    AddCountᶻUCommand::AddCountᶻUCommand(const Header&h) : 
        CountCommand(h)
    {
    }
    
    AddCountᶻUCommand::AddCountᶻUCommand(const Header&h, unsigned z) : 
        CountCommand(h), m_Δz(z)
    {
    }

    AddCountᶻUCommand::AddCountᶻUCommand(const AddCountᶻUCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddCountᶻUCommand::~AddCountᶻUCommand()
    {
    }

    PostCPtr    AddCountᶻUCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddCountᶻUCommand(*this, h);
    }
    
    void AddCountᶻUCommand::init_meta()
    {
        auto w = writer<AddCountᶻUCommand>();
        w.description("Add Count Command in Z");
        w.property("Δz", &AddCountᶻUCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
