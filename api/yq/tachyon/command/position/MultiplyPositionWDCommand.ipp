////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʷDCommand)

namespace yq::tachyon {
    MultiplyPositionʷDCommand::MultiplyPositionʷDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MultiplyPositionʷDCommand::MultiplyPositionʷDCommand(const Header&h, double w) : 
        PositionCommand(h), m_δw(w)
    {
    }

    MultiplyPositionʷDCommand::MultiplyPositionʷDCommand(const MultiplyPositionʷDCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyPositionʷDCommand::~MultiplyPositionʷDCommand()
    {
    }
    
    PostCPtr    MultiplyPositionʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʷDCommand(*this, h);
    }

    void MultiplyPositionʷDCommand::init_meta()
    {
        auto w = writer<MultiplyPositionʷDCommand>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPositionʷDCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
