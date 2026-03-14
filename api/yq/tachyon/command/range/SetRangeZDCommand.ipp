////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeᶻDCommand)

namespace yq::tachyon {
    SetRangeᶻDCommand::SetRangeᶻDCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeᶻDCommand::SetRangeᶻDCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_zRange(v)
    {
    }

    SetRangeᶻDCommand::SetRangeᶻDCommand(const SetRangeᶻDCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_zRange(cp.m_zRange)
    {
    }
    
    SetRangeᶻDCommand::~SetRangeᶻDCommand()
    {
    }

    PostCPtr    SetRangeᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeᶻDCommand(*this, h);
    }
    
    void SetRangeᶻDCommand::init_meta()
    {
        auto w = writer<SetRangeᶻDCommand>();
        w.description("Set Range Command in Z");
        w.property("z_range", &SetRangeᶻDCommand::m_zRange).tag(kTag_Log).tag(kTag_Save);
    }
}
