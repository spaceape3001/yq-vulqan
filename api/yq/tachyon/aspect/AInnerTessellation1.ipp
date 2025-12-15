////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AInnerTessellation1Writer.hxx"
#include <yq/tachyon/command/tessellation/SetInnerTessellation1Command.hpp>
#include <yq/tachyon/event/tessellation/SetInnerTessellation1Event.hpp>

namespace yq::tachyon {
    AInnerTessellation¹::AInnerTessellation¹(const Param& p) : m_innerTessellation(p.inner_tessellation)
    {
    }
    
    AInnerTessellation¹::AInnerTessellation¹(const Vector1D& it) : m_innerTessellation(it)
    {
    }
    
    AInnerTessellation¹::~AInnerTessellation¹()
    {
    }

    void        AInnerTessellation¹::inner_tessellation(emit_k)
    {
        send(new SetInnerTessellation¹Event({.source=typed()}, m_innerTessellation));
    }

    void        AInnerTessellation¹::inner_tessellation(set_k, const Vector1D& sz) 
    {
        m_innerTessellation  =    sz;
        mark();
        inner_tessellation(EMIT);
    }
    
    void        AInnerTessellation¹::on_set_inner_tessellation1(const SetInnerTessellation¹Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        inner_tessellation(SET, cmd.inner_tessellation());
    }
}
