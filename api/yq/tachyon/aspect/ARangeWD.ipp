////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeWD.hpp"
#include "ARangeWDWriter.hxx"
#include <yq/tachyon/command/range/SetRangeWDCommand.hpp>
#include <yq/tachyon/event/range/RangeWDEvent.hpp>


namespace yq::tachyon {

    ARangeʷD::ARangeʷD(const Param&p) : m_wRange(p.w_range)
    {
    }

    ARangeʷD::ARangeʷD(const RangeD& r) : m_wRange(r)
    {
    }
    
    ARangeʷD::~ARangeʷD()
    {
    }

    void        ARangeʷD::w_range(emit_k)
    {
        send(new RangeʷDEvent({.source=typed()}, m_wRange));
    }
    
    void        ARangeʷD::w_range(set_k, const RangeD& sz) 
    {
        m_wRange  =    sz;
        mark();
        w_range(EMIT);
    }
    
    void        ARangeʷD::on_set_w_range(const SetRangeʷDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        w_range(SET, cmd.w_range());
    }
}
