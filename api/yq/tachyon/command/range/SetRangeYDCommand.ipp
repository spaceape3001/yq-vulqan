////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeʸDCommand)

namespace yq::tachyon {
    SetRangeʸDCommand::SetRangeʸDCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeʸDCommand::SetRangeʸDCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_yRange(v)
    {
    }

    SetRangeʸDCommand::SetRangeʸDCommand(const SetRangeʸDCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_yRange(cp.m_yRange)
    {
    }
    
    SetRangeʸDCommand::~SetRangeʸDCommand()
    {
    }

    PostCPtr    SetRangeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeʸDCommand(*this, h);
    }
    
    void SetRangeʸDCommand::init_meta()
    {
        auto w = writer<SetRangeʸDCommand>();
        w.description("Set Range Command in Y");
        w.property("y_range", &SetRangeʸDCommand::m_yRange).tag(kTag_Log).tag(kTag_Save);
    }
}
