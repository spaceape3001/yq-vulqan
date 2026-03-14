////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeXD.hpp"
#include "ARangeXDWriter.hxx"
#include <yq/tachyon/command/range/SetRangeXDCommand.hpp>
#include <yq/tachyon/event/range/RangeXDEvent.hpp>


namespace yq::tachyon {
    ARangeˣD::ARangeˣD(const Param& p) : m_xRange(p.x_range)
    {
    }

    ARangeˣD::ARangeˣD(const RangeD& r) : m_xRange(r)
    {
    }
    
    ARangeˣD::~ARangeˣD()
    {
    }

    void        ARangeˣD::x_range(emit_k)
    {
        send(new RangeˣDEvent({.source=typed()}, m_xRange));
    }
    
    void        ARangeˣD::x_range(set_k, const RangeD& sz) 
    {
        m_xRange  =    sz;
        mark();
        x_range(EMIT);
    }
    
    void        ARangeˣD::on_set_x_range(const SetRangeˣDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        x_range(SET, cmd.x_range());
    }
}
