////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionˣDCommand)

namespace yq::tachyon {
    AddPositionˣDCommand::AddPositionˣDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionˣDCommand::AddPositionˣDCommand(const Header&h, double Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionˣDCommand::AddPositionˣDCommand(const AddPositionˣDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionˣDCommand::~AddPositionˣDCommand()
    {
    }
    
    PostCPtr    AddPositionˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionˣDCommand(*this, h);
    }

    void AddPositionˣDCommand::init_meta()
    {
        auto w = writer<AddPositionˣDCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δx", &AddPositionˣDCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
