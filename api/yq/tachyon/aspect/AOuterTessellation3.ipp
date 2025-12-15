////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AOuterTessellation3Writer.hxx"
#include <yq/tachyon/command/tessellation/SetOuterTessellation3Command.hpp>
#include <yq/tachyon/event/tessellation/SetOuterTessellation3Event.hpp>

namespace yq::tachyon {
    AOuterTessellation³::AOuterTessellation³(const Param& p) : m_outerTessellation(p.outer_tessellation)
    {
    }
    
    AOuterTessellation³::AOuterTessellation³(const Vector3D& it) : m_outerTessellation(it)
    {
    }
    
    AOuterTessellation³::~AOuterTessellation³()
    {
    }

    void        AOuterTessellation³::outer_tessellation(emit_k)
    {
        send(new SetOuterTessellation³Event({.source=typed()}, m_outerTessellation));
    }

    void        AOuterTessellation³::outer_tessellation(set_k, const Vector3D& sz) 
    {
        m_outerTessellation  =    sz;
        mark();
        outer_tessellation(EMIT);
    }
    
    void        AOuterTessellation³::on_set_outer_tessellation3(const SetOuterTessellation³Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        outer_tessellation(SET, cmd.outer_tessellation());
    }
}
