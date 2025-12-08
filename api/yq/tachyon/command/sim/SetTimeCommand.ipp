////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTimeCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTimeCommand)

namespace yq::tachyon {
    SetTimeCommand::SetTimeCommand(const Header&h, unit::Second _time) : 
        SimCommand(h), m_time(_time)
    {
    }
    
    SetTimeCommand::SetTimeCommand(const SetTimeCommand& cp, const Header&h) : 
        SimCommand(cp,h), m_time(cp.m_time)
    {
    }

    SetTimeCommand::~SetTimeCommand()
    {
    }

    PostCPtr    SetTimeCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetTimeCommand(*this, h);
    }
    
    void SetTimeCommand::init_meta()
    {
        auto w = writer<SetTimeCommand>();
        w.description("Set Time Command");
        w.property("time", &SetTimeCommand::m_time).tag({kTag_Save, kTag_Log});
    }
}
