////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeʸCommand)

namespace yq::tachyon {
    SetRangeʸCommand::SetRangeʸCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeʸCommand::SetRangeʸCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_yRange(v)
    {
    }

    SetRangeʸCommand::SetRangeʸCommand(const SetRangeʸCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_yRange(cp.m_yRange)
    {
    }
    
    SetRangeʸCommand::~SetRangeʸCommand()
    {
    }

    PostCPtr    SetRangeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeʸCommand(*this, h);
    }
    
    void SetRangeʸCommand::init_meta()
    {
        auto w = writer<SetRangeʸCommand>();
        w.description("Set Range Command in Y");
        w.property("y_range", &SetRangeʸCommand::m_yRange).tag(kTag_Log).tag(kTag_Save);
    }
}
