////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionᶻCommand)

namespace yq::tachyon {
    AddPositionᶻCommand::AddPositionᶻCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPositionᶻCommand::AddPositionᶻCommand(const Header&h, double Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    AddPositionᶻCommand::AddPositionᶻCommand(const AddPositionᶻCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionᶻCommand::~AddPositionᶻCommand()
    {
    }
    
    PostCPtr    AddPositionᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionᶻCommand(*this, h);
    }

    void AddPositionᶻCommand::init_meta()
    {
        auto w = writer<AddPositionᶻCommand>();
        w.description("Position AddPosition Command in Z");
        w.property("Δz", &AddPositionᶻCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
