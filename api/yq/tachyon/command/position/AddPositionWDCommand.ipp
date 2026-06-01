////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʷDCommand)

namespace yq::tachyon {
    AddPositionʷDCommand::AddPositionʷDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʷDCommand::AddPositionʷDCommand(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    AddPositionʷDCommand::AddPositionʷDCommand(const AddPositionʷDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddPositionʷDCommand::~AddPositionʷDCommand()
    {
    }
    
    PostCPtr    AddPositionʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionʷDCommand(*this, h);
    }

    void AddPositionʷDCommand::init_meta()
    {
        auto w = writer<AddPositionʷDCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δw", &AddPositionʷDCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
