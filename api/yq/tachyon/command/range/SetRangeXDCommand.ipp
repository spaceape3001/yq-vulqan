////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeˣDCommand)

namespace yq::tachyon {
    SetRangeˣDCommand::SetRangeˣDCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeˣDCommand::SetRangeˣDCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_xRange(v)
    {
    }

    SetRangeˣDCommand::SetRangeˣDCommand(const SetRangeˣDCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_xRange(cp.m_xRange)
    {
    }
    
    SetRangeˣDCommand::~SetRangeˣDCommand()
    {
    }

    PostCPtr    SetRangeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeˣDCommand(*this, h);
    }
    
    void SetRangeˣDCommand::init_meta()
    {
        auto w = writer<SetRangeˣDCommand>();
        w.description("Set Range Command in X");
        w.property("x_range", &SetRangeˣDCommand::m_xRange).tag(kTag_Log).tag(kTag_Save);
    }
}
