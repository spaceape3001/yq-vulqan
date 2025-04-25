////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/N.hpp>
#include <tachyon/api/NData.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/command/SpatialCommand.hpp>
#include <tachyon/event/SpatialEvent.hpp>
#include <yt/logging.hpp>

namespace yq::tachyon {

    ИSnap::~ИSnap()
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ИData::~ИData()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    И::И()
    {
    }
    
    И::~И()
    {
    }

    void    И::finalize(ИData&) const
    {
        // nothing to do (AT THE MOMENT)
    }

    void    И::on_spatial_command(const SpatialCommand&cmd)
    {
        if(!m_spatial)
            return;

        send(cmd.clone(REBIND, {.target=m_spatial}), TARGET);
    }

    void    И::on_spatial_event(const SpatialEvent&evt)
    {
        if(evt.source() != m_spatial)
            return;
            
        send(evt.clone(REBIND, {.source=typed()}));
    }

    void    И::set_spatial(TypedID sid)
    {
        if(sid(Type::Spatial)){
            m_spatial   = sid;
            // TODO (subscribe spatial to us)
            mark();
        }
    }

    void    И::snap(ИSnap& sn) const
    {
        sn.spatial  = (SpatialID) m_spatial.id;
    }

    TachyonID   И::tachyon_id() const
    {
        const Tachyon* t    = dynamic_cast<const Tachyon*>(this);
        if(t)
            return t->id();
        return {};
    }
}
