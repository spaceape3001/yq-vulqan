////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyPositionWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyPositionʷCommand)

namespace yq::tachyon {
    MultiplyPositionʷCommand::MultiplyPositionʷCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MultiplyPositionʷCommand::MultiplyPositionʷCommand(const Header&h, double w) : 
        PositionCommand(h), m_δw(w)
    {
    }

    MultiplyPositionʷCommand::MultiplyPositionʷCommand(const MultiplyPositionʷCommand& cp, const Header& h) : 
        PositionCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyPositionʷCommand::~MultiplyPositionʷCommand()
    {
    }
    
    PostCPtr    MultiplyPositionʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyPositionʷCommand(*this, h);
    }

    void MultiplyPositionʷCommand::init_meta()
    {
        auto w = writer<MultiplyPositionʷCommand>();
        w.description("Multiply Position Command");
        w.property("δw", &MultiplyPositionʷCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
