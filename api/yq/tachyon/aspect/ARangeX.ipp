////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeXWriter.hxx"
#include "ARangeX.hpp"
#include <yq/tachyon/command/range/SetRangeXCommand.hpp>
#include <yq/tachyon/event/range/RangeXEvent.hpp>


namespace yq::tachyon {
    ARangeˣ::ARangeˣ(const Param& p) : m_xRange(p.x_range)
    {
    }

    ARangeˣ::ARangeˣ(const RangeD& r) : m_xRange(r)
    {
    }
    
    ARangeˣ::~ARangeˣ()
    {
    }

    void        ARangeˣ::x_range(emit_k)
    {
        send(new RangeˣEvent({.source=typed()}, m_xRange));
    }
    
    void        ARangeˣ::x_range(set_k, const RangeD& sz) 
    {
        m_xRange  =    sz;
        mark();
        x_range(EMIT);
    }
    
    void        ARangeˣ::on_set_x_range(const SetRangeˣCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        x_range(SET, cmd.x_range());
    }
}
