////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/color/SetColorCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetColorCommand)

namespace yq::tachyon {

    SetColorCommand::SetColorCommand(const Header&h, const RGBA4F&v) : 
        ColorCommand(h), m_color(v)
    {
    }

    SetColorCommand::SetColorCommand(const SetColorCommand& cp, const Header& h) : 
        ColorCommand(cp, h), m_color(cp.m_color)
    {
    }
    
    SetColorCommand::~SetColorCommand()
    {
    }

    PostCPtr    SetColorCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetColorCommand(*this, h);
    }
    
    void        SetColorCommand::set_color(const RGBA4F&v)
    {
        m_color   = v;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetColorCommand::init_meta()
    {
        auto w = writer<SetColorCommand>();
        w.description("Set Color Command");
        w.property("color", &SetColorCommand::m_color);
    }
}
