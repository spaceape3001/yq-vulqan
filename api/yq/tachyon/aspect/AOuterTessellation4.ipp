////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AOuterTessellation4Writer.hxx"
#include <yq/tachyon/command/tessellation/SetOuterTessellation4Command.hpp>
#include <yq/tachyon/event/tessellation/SetOuterTessellation4Event.hpp>

namespace yq::tachyon {
    AOuterTessellation⁴::AOuterTessellation⁴(const Param& p) : m_outerTessellation(p.outer_tessellation)
    {
    }
    
    AOuterTessellation⁴::AOuterTessellation⁴(const Vector4D& it) : m_outerTessellation(it)
    {
    }
    
    AOuterTessellation⁴::~AOuterTessellation⁴()
    {
    }

    void        AOuterTessellation⁴::outer_tessellation(emit_k)
    {
        send(new SetOuterTessellation⁴Event({.source=typed()}, m_outerTessellation));
    }

    void        AOuterTessellation⁴::outer_tessellation(set_k, const Vector4D& sz) 
    {
        m_outerTessellation  =    sz;
        mark();
        outer_tessellation(EMIT);
    }
    
    void        AOuterTessellation⁴::on_set_outer_tessellation4(const SetOuterTessellation⁴Command&cmd)
    {
        if(cmd.target() != typed())
            return;
        outer_tessellation(SET, cmd.outer_tessellation());
    }
}
