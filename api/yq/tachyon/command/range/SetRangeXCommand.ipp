////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeˣCommand)

namespace yq::tachyon {
    SetRangeˣCommand::SetRangeˣCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeˣCommand::SetRangeˣCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_xRange(v)
    {
    }

    SetRangeˣCommand::SetRangeˣCommand(const SetRangeˣCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_xRange(cp.m_xRange)
    {
    }
    
    SetRangeˣCommand::~SetRangeˣCommand()
    {
    }

    PostCPtr    SetRangeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeˣCommand(*this, h);
    }
    
    void SetRangeˣCommand::init_meta()
    {
        auto w = writer<SetRangeˣCommand>();
        w.description("Set Range Command in X");
        w.property("x_range", &SetRangeˣCommand::m_xRange).tag(kTag_Log).tag(kTag_Save);
    }
}
