////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeʷCommand)

namespace yq::tachyon {
    SetRangeʷCommand::SetRangeʷCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeʷCommand::SetRangeʷCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_wRange(v)
    {
    }

    SetRangeʷCommand::SetRangeʷCommand(const SetRangeʷCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_wRange(cp.m_wRange)
    {
    }
    
    SetRangeʷCommand::~SetRangeʷCommand()
    {
    }

    PostCPtr    SetRangeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeʷCommand(*this, h);
    }
    
    void SetRangeʷCommand::init_meta()
    {
        auto w = writer<SetRangeʷCommand>();
        w.description("Set Range Command in X");
        w.property("w_range", &SetRangeʷCommand::m_wRange).tag(kTag_Log).tag(kTag_Save);
    }
}
