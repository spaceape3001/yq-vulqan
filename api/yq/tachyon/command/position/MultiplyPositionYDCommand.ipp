////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʸDCommand)

namespace yq::tachyon {
    MultiplyPositionʸDCommand::MultiplyPositionʸDCommand(const Header& h) : 
        PositionCommand(h)
    {
    }
    
    MultiplyPositionʸDCommand::MultiplyPositionʸDCommand(const Header& h, double y) : 
        PositionCommand(h), m_δy(y)
    {
    }

    MultiplyPositionʸDCommand::MultiplyPositionʸDCommand(const MultiplyPositionʸDCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyPositionʸDCommand::~MultiplyPositionʸDCommand()
    {
    }

    PostCPtr    MultiplyPositionʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʸDCommand(*this, h);
    }
    
    void MultiplyPositionʸDCommand::init_meta()
    {
        auto w = writer<MultiplyPositionʸDCommand>();
        w.description("Multiply Position Command");
        w.property("δy", &MultiplyPositionʸDCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
