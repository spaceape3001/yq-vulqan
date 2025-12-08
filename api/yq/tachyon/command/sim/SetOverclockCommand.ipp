////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOverclockCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOverclockCommand)

namespace yq::tachyon {
    SetOverclockCommand::SetOverclockCommand(const Header&h, double _overclock) : 
        SimCommand(h), m_overclock(_overclock)
    {
    }
    
    SetOverclockCommand::SetOverclockCommand(const SetOverclockCommand& cp, const Header&h) : 
        SimCommand(cp,h), m_overclock(cp.m_overclock)
    {
    }

    SetOverclockCommand::~SetOverclockCommand()
    {
    }

    PostCPtr    SetOverclockCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetOverclockCommand(*this, h);
    }
    
    void SetOverclockCommand::init_meta()
    {
        auto w = writer<SetOverclockCommand>();
        w.description("Set Overclock Command");
        w.property("overclock", &SetOverclockCommand::m_overclock).tag({kTag_Save, kTag_Log});
    }
}
