////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeʷDCommand)

namespace yq::tachyon {
    SetRangeʷDCommand::SetRangeʷDCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeʷDCommand::SetRangeʷDCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_wRange(v)
    {
    }

    SetRangeʷDCommand::SetRangeʷDCommand(const SetRangeʷDCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_wRange(cp.m_wRange)
    {
    }
    
    SetRangeʷDCommand::~SetRangeʷDCommand()
    {
    }

    PostCPtr    SetRangeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeʷDCommand(*this, h);
    }
    
    void SetRangeʷDCommand::init_meta()
    {
        auto w = writer<SetRangeʷDCommand>();
        w.description("Set Range Command in X");
        w.property("w_range", &SetRangeʷDCommand::m_wRange).tag(kTag_Log).tag(kTag_Save);
    }
}
