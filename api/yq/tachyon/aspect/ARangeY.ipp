////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeYWriter.hxx"
#include "ARangeY.hpp"
#include <yq/tachyon/command/range/SetRangeYCommand.hpp>
#include <yq/tachyon/event/range/RangeYEvent.hpp>


namespace yq::tachyon {
    ARangeʸ::ARangeʸ(const Param&p) : m_yRange(p.y_range)
    {
    }

    ARangeʸ::ARangeʸ(const RangeD& r) : m_yRange(r)
    {
    }
    
    ARangeʸ::~ARangeʸ()
    {
    }

    void        ARangeʸ::y_range(emit_k)
    {
        send(new RangeʸEvent({.source=typed()}, m_yRange));
    }
    
    void        ARangeʸ::y_range(set_k, const RangeD& sz) 
    {
        m_yRange  =    sz;
        mark();
        y_range(EMIT);
    }
    
    void        ARangeʸ::on_set_y_range(const SetRangeʸCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        y_range(SET, cmd.y_range());
    }
}
