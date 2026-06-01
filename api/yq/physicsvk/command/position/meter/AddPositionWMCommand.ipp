////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionWMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʷMCommand)

namespace yq::tachyon {
    AddPositionʷMCommand::AddPositionʷMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʷMCommand::AddPositionʷMCommand(const Header&h, Meter Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    AddPositionʷMCommand::AddPositionʷMCommand(const AddPositionʷMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddPositionʷMCommand::~AddPositionʷMCommand()
    {
    }
    
    PostCPtr    AddPositionʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionʷMCommand(*this, h);
    }

    void AddPositionʷMCommand::init_meta()
    {
        auto w = writer<AddPositionʷMCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δw", &AddPositionʷMCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
