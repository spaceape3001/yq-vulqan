////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount3UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount³UCommand)

namespace yq::tachyon {
    SetCount³UCommand::SetCount³UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount³UCommand::SetCount³UCommand(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount³UCommand::SetCount³UCommand(const SetCount³UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount³UCommand::~SetCount³UCommand()
    {
    }

    PostCPtr    SetCount³UCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCount³UCommand(*this, h);
    }
    
    void SetCount³UCommand::init_meta()
    {
        auto w = writer<SetCount³UCommand>();
        w.description("Set Count Command in 3D");
        w.property("x", &SetCount³UCommand::x).tag(kTag_Log);
        w.property("y", &SetCount³UCommand::y).tag(kTag_Log);
        w.property("z", &SetCount³UCommand::z).tag(kTag_Log);
        w.property("count", &SetCount³UCommand::m_count).tag(kTag_Save);
    }
}
