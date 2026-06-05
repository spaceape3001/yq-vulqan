////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionWCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʷCMCommand)

namespace yq::tachyon {
    AddPositionʷCMCommand::AddPositionʷCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʷCMCommand::AddPositionʷCMCommand(const Header&h, Centimeter Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    AddPositionʷCMCommand::AddPositionʷCMCommand(const AddPositionʷCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddPositionʷCMCommand::~AddPositionʷCMCommand()
    {
    }
    
    PostCPtr    AddPositionʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionʷCMCommand(*this, h);
    }

    void AddPositionʷCMCommand::init_meta()
    {
        auto w = writer<AddPositionʷCMCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δw", &AddPositionʷCMCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
