////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CircularSpatial3.hpp"
#include "CircularSpatial3Data.hpp"
#include <yq/math/trigonometry.hpp>
#include <yq/math/utility.hpp>
#include <yq/assetvk/command/circular3/Circular3LockCommand.hpp>
#include <yq/assetvk/command/circular3/Circular3PeriodCommand.hpp>
#include <yq/assetvk/command/circular3/Circular3RadiusCommand.hpp>
#include <yq/assetvk/event/circular3/Circular3LockEvent.hpp>
#include <yq/assetvk/event/circular3/Circular3PeriodEvent.hpp>
#include <yq/assetvk/event/circular3/Circular3RadiusEvent.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/trait/numbers.hpp>
#include <yq/vector/Quaternion3.hpp>

#include <yq/tachyon/aspect/AOrientation3Writer.hxx>
#include <yq/tachyon/aspect/APosition3Writer.hxx>
#include <yq/tachyon/aspect/AScale3Writer.hxx>
#include <yq/tensor/Tensor33.hxx>
#include <yq/vector/Quaternion3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CircularSpatial³)

namespace yq::tachyon {
    void CircularSpatial³::init_meta()
    {
        auto w = writer<CircularSpatial³>();
        w.property("angle0", &CircularSpatial³::m_angle0).tag(kTag_Save);
        w.property("locked", &CircularSpatial³::m_locked).tag(kTag_Save);
        w.property("period", &CircularSpatial³::m_period).tag(kTag_Save);
        w.property("radius", &CircularSpatial³::m_radius).tag(kTag_Save);
        w.slot(&CircularSpatial³::on_lock_command);
        w.slot(&CircularSpatial³::on_period_command);
        w.slot(&CircularSpatial³::on_radius_command);
        APosition³::init_meta(w);
        AScale³::init_meta(w);
        AOrientation³::init_meta(w);
    }


    CircularSpatial³::CircularSpatial³() : CircularSpatial³(Param())
    {
    }

    CircularSpatial³::CircularSpatial³(const Param& p) : Spatial³(p), 
        m_angle0(p.angle0),
        m_locked(p.locked),
        m_period(p.period),
        m_radius(p.radius)
    {
    }
    
    CircularSpatial³::~CircularSpatial³()
    {
    }
    
    void    CircularSpatial³::on_lock_command(const Circular³LockCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_locked    = cmd.lock();
        send(new Circular³LockEvent({}, m_locked));
        mark();
    }

    void    CircularSpatial³::on_period_command(const Circular³PeriodCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_period    = cmd.period();
        send(new Circular³PeriodEvent({}, m_period));
        mark();
    }
    
    void    CircularSpatial³::on_radius_command(const Circular³RadiusCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_radius    = cmd.radius();
        send(new Circular³RadiusEvent({}, m_radius));
        mark();
    }

    Vector3D CircularSpatial³::position() const
    {
        return m_position;
    }
    
    void CircularSpatial³::snap(CircularSpatial³Snap& sn) const
    {
        Spatial³::snap(sn, m_position + m_local, m_locked ? m_orientation : Quaternion3D(IDENTITY), m_scale);
        
        sn.period   = m_period;
        sn.radius   = m_radius;
        sn.angle    = m_angle;
        sn.angle0   = m_angle0;
        sn.locked   = m_locked;
    }

    Execution CircularSpatial³::tick(const Context& u)
    {
        m_angle  = wrap<Radian>(m_angle0 + Radian(two_pi) * u.time / m_period, 0., two_pi);
        m_local  = m_orientation * Vector3D(m_radius*cos(m_angle), m_radius*sin(m_angle), 0.);
        mark();
        return Spatial³::tick(u);
    }
}

