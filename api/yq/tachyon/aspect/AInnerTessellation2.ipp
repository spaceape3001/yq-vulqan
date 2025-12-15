////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AInnerTessellation2Writer.hxx"
#include <yq/tachyon/command/tessellation/SetInnerTessellation2Command.hpp>
#include <yq/tachyon/event/tessellation/SetInnerTessellation2Event.hpp>

namespace yq::tachyon {
    AInnerTessellation²::AInnerTessellation²(const Param& p) : m_innerTessellation(p.inner_tessellation)
    {
    }
    
    AInnerTessellation²::AInnerTessellation²(const Vector2D& it) : m_innerTessellation(it)
    {
    }
    
    AInnerTessellation²::~AInnerTessellation²()
    {
    }

    void        AInnerTessellation²::inner_tessellation(emit_k)
    {
        send(new SetInnerTessellation²Event({.source=typed()}, m_innerTessellation));
    }

    void        AInnerTessellation²::inner_tessellation(set_k, const Vector2D& sz) 
    {
        m_innerTessellation  =    sz;
        mark();
        inner_tessellation(EMIT);
    }
    
    void        AInnerTessellation²::on_set_inner_tessellation2(const SetInnerTessellation²Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        inner_tessellation(SET, cmd.inner_tessellation());
    }
}
