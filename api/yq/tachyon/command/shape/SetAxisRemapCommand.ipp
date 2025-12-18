////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetAxisRemapCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetAxisRemapCommand)

namespace yq::tachyon {
    SetAxisRemapCommand::SetAxisRemapCommand(const Header& h, AxisRemap _axisRemap) : ShapeCommand(h), m_axisRemap(_axisRemap)
    {
    }
    
    SetAxisRemapCommand::SetAxisRemapCommand(const SetAxisRemapCommand&cp, const Header&h) : 
        ShapeCommand(cp, h), m_axisRemap(cp.m_axisRemap)
    {
    }

    SetAxisRemapCommand::~SetAxisRemapCommand()
    {
    }
    
    PostCPtr    SetAxisRemapCommand::clone(rebind_k, const Header&h) const
    {
        return new SetAxisRemapCommand(*this, h);
    }

    void SetAxisRemapCommand::init_meta()
    {
        auto w = writer<SetAxisRemapCommand>();
        w.description(" AxisRemap Command");
        w.property("axis_remap", &SetAxisRemapCommand::m_axisRemap);
    }
}
