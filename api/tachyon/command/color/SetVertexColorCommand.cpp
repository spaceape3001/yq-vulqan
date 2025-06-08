////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/color/SetVertexColorCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexColorCommand)

namespace yq::tachyon {

    SetVertexColorCommand::SetVertexColorCommand(const Header&h, unsigned v, const RGBA4F&clr) : 
        ColorCommand(h), m_bgColor(clr), m_vertex(v)
    {
    }

    SetVertexColorCommand::SetVertexColorCommand(const SetVertexColorCommand& cp, const Header& h) : 
        ColorCommand(cp, h), m_bgColor(cp.m_bgColor), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexColorCommand::~SetVertexColorCommand()
    {
    }

    PostCPtr    SetVertexColorCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexColorCommand(*this, h);
    }
    
    void        SetVertexColorCommand::set_bgcolor(const RGBA4F&v)
    {
        m_bgColor   = v;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexColorCommand::init_info()
    {
        auto w = writer<SetVertexColorCommand>();
        w.description("SetVertexColor Command");
        w.property("bgcolor", &SetVertexColorCommand::m_bgColor).tag(kTag_Save);
        w.property("vertex", &SetVertexColorCommand::m_vertex).tag(kTag_Save).tag(kTag_Log);
    }
}
