////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexColorCommand.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexColorCommand)

namespace yq::tachyon {

    SetVertexColorCommand::SetVertexColorCommand(const Header&h, size_t v, const RGBA4F&clr) : 
        VertexCommand(h), m_color(clr), m_vertex(v)
    {
    }

    SetVertexColorCommand::SetVertexColorCommand(const SetVertexColorCommand& cp, const Header& h) : 
        VertexCommand(cp, h), m_color(cp.m_color), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexColorCommand::~SetVertexColorCommand()
    {
    }

    PostCPtr    SetVertexColorCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexColorCommand(*this, h);
    }
    
    void        SetVertexColorCommand::set_color(const RGBA4F&v)
    {
        m_color   = v;
    }

    void        SetVertexColorCommand::set_vertex(size_t n)
    {
        m_vertex    = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexColorCommand::init_meta()
    {
        auto w = writer<SetVertexColorCommand>();
        w.description("Set Vertex Color Command");
        w.property("vertex", &SetVertexColorCommand::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("color", &SetVertexColorCommand::m_color).tag(kTag_Save);
        w.property("red", &SetVertexColorCommand::red).tag(kTag_Log);
        w.property("green", &SetVertexColorCommand::green).tag(kTag_Log);
        w.property("blue", &SetVertexColorCommand::blue).tag(kTag_Log);
        w.property("alpha", &SetVertexColorCommand::alpha).tag(kTag_Log);
    }
}
