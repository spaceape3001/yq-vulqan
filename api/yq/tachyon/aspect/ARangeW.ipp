////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeWWriter.hxx"
#include "ARangeW.hpp"
#include <yq/tachyon/command/range/SetRangeWCommand.hpp>
#include <yq/tachyon/event/range/RangeWEvent.hpp>


namespace yq::tachyon {

    ARangeʷ::ARangeʷ(const Param&p) : m_wRange(p.w_range)
    {
    }

    ARangeʷ::ARangeʷ(const RangeD& r) : m_wRange(r)
    {
    }
    
    ARangeʷ::~ARangeʷ()
    {
    }

    void        ARangeʷ::w_range(emit_k)
    {
        send(new RangeʷEvent({.source=typed()}, m_wRange));
    }
    
    void        ARangeʷ::w_range(set_k, const RangeD& sz) 
    {
        m_wRange  =    sz;
        mark();
        w_range(EMIT);
    }
    
    void        ARangeʷ::on_set_w_range(const SetRangeʷCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        w_range(SET, cmd.w_range());
    }
}
