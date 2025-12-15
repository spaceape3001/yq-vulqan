////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetRangeZCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRangeᶻCommand)

namespace yq::tachyon {
    SetRangeᶻCommand::SetRangeᶻCommand(const Header& h) : 
        RangeCommand(h)
    {
    }

    SetRangeᶻCommand::SetRangeᶻCommand(const Header& h, const RangeD& v) : 
        RangeCommand(h), m_zRange(v)
    {
    }

    SetRangeᶻCommand::SetRangeᶻCommand(const SetRangeᶻCommand& cp, const Header& h) : 
        RangeCommand(cp, h), m_zRange(cp.m_zRange)
    {
    }
    
    SetRangeᶻCommand::~SetRangeᶻCommand()
    {
    }

    PostCPtr    SetRangeᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRangeᶻCommand(*this, h);
    }
    
    void SetRangeᶻCommand::init_meta()
    {
        auto w = writer<SetRangeᶻCommand>();
        w.description("Set Range Command in Z");
        w.property("z_range", &SetRangeᶻCommand::m_zRange).tag(kTag_Log).tag(kTag_Save);
    }
}
