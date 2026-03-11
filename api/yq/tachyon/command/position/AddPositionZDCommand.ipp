////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionᶻDCommand)

namespace yq::tachyon {
    AddPositionᶻDCommand::AddPositionᶻDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPositionᶻDCommand::AddPositionᶻDCommand(const Header&h, double Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    AddPositionᶻDCommand::AddPositionᶻDCommand(const AddPositionᶻDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionᶻDCommand::~AddPositionᶻDCommand()
    {
    }
    
    PostCPtr    AddPositionᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionᶻDCommand(*this, h);
    }

    void AddPositionᶻDCommand::init_meta()
    {
        auto w = writer<AddPositionᶻDCommand>();
        w.description("Position AddPosition Command in Z");
        w.property("Δz", &AddPositionᶻDCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
