////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddOffsetZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddOffsetᶻCommand)

namespace yq::tachyon {
    AddOffsetᶻCommand::AddOffsetᶻCommand(const Header&h) : 
        OffsetCommand(h)
    {
    }
    
    AddOffsetᶻCommand::AddOffsetᶻCommand(const Header&h, double Δz) : 
        OffsetCommand(h), m_Δz(Δz)
    {
    }

    AddOffsetᶻCommand::AddOffsetᶻCommand(const AddOffsetᶻCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddOffsetᶻCommand::~AddOffsetᶻCommand()
    {
    }
    
    PostCPtr    AddOffsetᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddOffsetᶻCommand(*this, h);
    }

    void AddOffsetᶻCommand::init_meta()
    {
        auto w = writer<AddOffsetᶻCommand>();
        w.description("Offset AddOffset Command in Z");
        w.property("Δz", &AddOffsetᶻCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
