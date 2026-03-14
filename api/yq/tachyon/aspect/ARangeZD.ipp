////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeZD.hpp"
#include "ARangeZDWriter.hxx"
#include <yq/tachyon/command/range/SetRangeZDCommand.hpp>
#include <yq/tachyon/event/range/RangeZDEvent.hpp>


namespace yq::tachyon {
    ARangeᶻD::ARangeᶻD(const Param& p) : m_zRange(p.z_range)
    {
    }

    ARangeᶻD::ARangeᶻD(const RangeD& r) : m_zRange(r)
    {
    }
    
    ARangeᶻD::~ARangeᶻD()
    {
    }

    void        ARangeᶻD::z_range(emit_k)
    {
        send(new RangeᶻDEvent({.source=typed()}, m_zRange));
    }
    
    void        ARangeᶻD::z_range(set_k, const RangeD& sz) 
    {
        m_zRange  =    sz;
        mark();
        z_range(EMIT);
    }
    
    void        ARangeᶻD::on_set_z_range(const SetRangeᶻDCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        z_range(SET, cmd.z_range());
    }
}
