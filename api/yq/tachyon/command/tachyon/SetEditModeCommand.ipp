////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetEditModeCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetEditModeCommand)

namespace yq::tachyon {

    SetEditModeCommand::SetEditModeCommand(const Header&h, Tristate em) : TachyonCommand(h), m_editMode(em)
    {
    }

    SetEditModeCommand::SetEditModeCommand(const SetEditModeCommand& cp, const Header& h) : 
        TachyonCommand(cp, h), m_editMode(cp.m_editMode)
    {
    }
    
    SetEditModeCommand::~SetEditModeCommand()
    {
    }

    PostCPtr    SetEditModeCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetEditModeCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetEditModeCommand::init_meta()
    {
        auto w = writer<SetEditModeCommand>();
        w.description("Set Edit Mode Command");
        w.property("edit_mode", &SetEditModeCommand::m_editMode);
    }
}
