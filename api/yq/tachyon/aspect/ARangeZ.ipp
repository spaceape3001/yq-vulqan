////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ARangeZWriter.hxx"
#include "ARangeZ.hpp"
#include <yq/tachyon/command/range/SetRangeZCommand.hpp>
#include <yq/tachyon/event/range/RangeZEvent.hpp>


namespace yq::tachyon {
    ARangeᶻ::ARangeᶻ()
    {
    }
    
    ARangeᶻ::~ARangeᶻ()
    {
    }

    void        ARangeᶻ::z_range(emit_k)
    {
        send(new RangeᶻEvent({.source=typed()}, m_zRange));
    }
    
    void        ARangeᶻ::z_range(set_k, const RangeD& sz) 
    {
        m_zRange  =    sz;
        mark();
        z_range(EMIT);
    }
    
    void        ARangeᶻ::on_set_z_range(const SetRangeᶻCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        z_range(SET, cmd.z_range());
    }
}
