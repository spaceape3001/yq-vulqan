////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "N.hpp"
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/NData.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/command/generic/SetSpatialCommand.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/tachyon/logging.hpp>

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

    void    И::on_set_spatial_command(const SetSpatialCommand&cmd)
    {
        if(cmd.target() != typed())
            return ;
        set_spatial(cmd.spatial());
        mark();
    }

    void    И::set_spatial(TypedID sid)
    {
        if(sid == m_spatial)
            return;
        if(m_spatial){
            // TODO (unsubscribe old spatial)
        }

        m_spatial   = sid;
        if(m_spatial){
            // TODO (subscribe new spatial to us)
        }
        mark();
    }

    void    И::set_spatial(SpatialID sid)
    {
        if(sid == m_spatial)
            return ;
    
        if(sid){
            if(const Frame* f  = Frame::current()){
                TypedID tid = f->typed(sid);
                if(tid){
                    set_spatial(tid);
                }
            } else {
                //  assume....
                set_spatial(TypedID( sid.id, Type::Spatial ));
            }
        } else {
            set_spatial(TypedID{});
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
