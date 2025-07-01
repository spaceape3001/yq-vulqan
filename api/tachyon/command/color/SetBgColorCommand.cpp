////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/color/SetBgColorCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetBgColorCommand)

namespace yq::tachyon {

    SetBgColorCommand::SetBgColorCommand(const Header&h, const RGBA4F&v) : 
        ColorCommand(h), m_bgColor(v)
    {
    }

    SetBgColorCommand::SetBgColorCommand(const SetBgColorCommand& cp, const Header& h) : 
        ColorCommand(cp, h), m_bgColor(cp.m_bgColor)
    {
    }
    
    SetBgColorCommand::~SetBgColorCommand()
    {
    }

    PostCPtr    SetBgColorCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetBgColorCommand(*this, h);
    }
    
    void        SetBgColorCommand::set_bgcolor(const RGBA4F&v)
    {
        m_bgColor   = v;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetBgColorCommand::init_info()
    {
        auto w = writer<SetBgColorCommand>();
        w.description("SetBgColor Command");
        w.property("bgcolor", &SetBgColorCommand::m_bgColor);
    }
}
