////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeYD.hpp"
#include "ARangeYDWriter.hxx"
#include <yq/tachyon/command/range/SetRangeYDCommand.hpp>
#include <yq/tachyon/event/range/RangeYDEvent.hpp>


namespace yq::tachyon {
    ARangeʸD::ARangeʸD(const Param&p) : m_yRange(p.y_range)
    {
    }

    ARangeʸD::ARangeʸD(const RangeD& r) : m_yRange(r)
    {
    }
    
    ARangeʸD::~ARangeʸD()
    {
    }

    void        ARangeʸD::y_range(emit_k)
    {
        send(new RangeʸDEvent({.source=typed()}, m_yRange));
    }
    
    void        ARangeʸD::y_range(set_k, const RangeD& sz) 
    {
        m_yRange  =    sz;
        mark();
        y_range(EMIT);
    }
    
    void        ARangeʸD::on_set_y_range(const SetRangeʸDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        y_range(SET, cmd.y_range());
    }
}
