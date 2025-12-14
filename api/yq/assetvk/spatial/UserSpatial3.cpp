////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UserSpatial3.hpp"
#include "UserSpatial3Data.hpp"
#include <yq/assetvk/command/user3/User3HCommand.hpp>
#include <yq/assetvk/command/user3/User3PCommand.hpp>
#include <yq/assetvk/command/user3/User3RCommand.hpp>
#include <yq/assetvk/command/user3/User3XCommand.hpp>
#include <yq/assetvk/command/user3/User3YCommand.hpp>
#include <yq/assetvk/command/user3/User3ZCommand.hpp>
#include <yq/assetvk/event/user3/User3HEvent.hpp>
#include <yq/assetvk/event/user3/User3PEvent.hpp>
#include <yq/assetvk/event/user3/User3REvent.hpp>
#include <yq/assetvk/event/user3/User3XEvent.hpp>
#include <yq/assetvk/event/user3/User3YEvent.hpp>
#include <yq/assetvk/event/user3/User3ZEvent.hpp>
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/userexpr/Context.hpp>
#include <yq/vector/Quaternion3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::UserSpatial³)

namespace yq::tachyon {
    UserSpatial³::Value::Value() = default;
    UserSpatial³::Value::~Value() = default;

    UserSpatial³::Value& UserSpatial³::Value::operator=(const Algebra& s)
    {
        algebra     = s;
        userexpr    = UserExpr(algebra);
        return *this;
    }
    
    void    UserSpatial³::Value::tick(expr::Context&u)
    {
        do {
            if(!userexpr.is_good())
                break;
            auto ax = userexpr.evaluate(u);
            if(!ax)
                break;
            auto vx = (*ax).value<double>();
            if(!vx.good)
                break;
            value   = vx.value;
            return ;
        } while(false);
        
        value   = 0;
    }

    void UserSpatial³::init_meta()
    {
        auto w = writer<UserSpatial³>();
        w.description("Spatial³ using user-defined expressions");
        w.interface<IPosition³>();
        w.interface<IOrientation³>();
        w.property("h", &UserSpatial³::h).setter(&UserSpatial³::set_h).tag(kTag_Save);
        w.property("p", &UserSpatial³::p).setter(&UserSpatial³::set_p).tag(kTag_Save);
        w.property("r", &UserSpatial³::r).setter(&UserSpatial³::set_r).tag(kTag_Save);
        w.property("x", &UserSpatial³::x).setter(&UserSpatial³::set_x).tag(kTag_Save);
        w.property("y", &UserSpatial³::y).setter(&UserSpatial³::set_y).tag(kTag_Save);
        w.property("z", &UserSpatial³::z).setter(&UserSpatial³::set_z).tag(kTag_Save);
        w.slot(&UserSpatial³::on_h_command);
        w.slot(&UserSpatial³::on_p_command);
        w.slot(&UserSpatial³::on_r_command);
        w.slot(&UserSpatial³::on_x_command);
        w.slot(&UserSpatial³::on_y_command);
        w.slot(&UserSpatial³::on_z_command);
    }

    UserSpatial³::UserSpatial³() : Spatial³()
    {
    }
    
    UserSpatial³::UserSpatial³(const Param& p) : Spatial³(p)
    {
        m_h = p.h;
        m_p = p.p;
        m_r = p.r;
        m_x = p.x;
        m_y = p.y;
        m_z = p.z;
    }
    
    UserSpatial³::~UserSpatial³()
    {
    }


    void UserSpatial³::on_h_command(const User³HCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_h = cmd.h();
        send(new User³HEvent({}, m_h.algebra));
        mark();
    }
    
    void UserSpatial³::on_p_command(const User³PCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_p = cmd.p();
        send(new User³PEvent({}, m_p.algebra));
        mark();
    }
    
    void UserSpatial³::on_r_command(const User³RCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_r = cmd.r();
        send(new User³REvent({}, m_r.algebra));
        mark();
    }
    
    void UserSpatial³::on_x_command(const User³XCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_x = cmd.x();
        send(new User³XEvent({}, m_x.algebra));
        mark();
    }
    
    void UserSpatial³::on_y_command(const User³YCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_y = cmd.y();
        send(new User³YEvent({}, m_y.algebra));
        mark();
    }
    
    void UserSpatial³::on_z_command(const User³ZCommand&cmd)
    {
        if(cmd.target() != id())
            return;
        m_z = cmd.z();
        send(new User³ZEvent({}, m_z.algebra));
        mark();
    }
    

    Quaternion3D    UserSpatial³::orientation() const
    {
        return m_orientation;
    }
    
    Vector3D    UserSpatial³::position() const
    {
        return m_position;
    }

    void    UserSpatial³::set_h(const Algebra&alg)
    {
        m_h = alg;
    }
    
    void    UserSpatial³::set_p(const Algebra&alg)
    {
        m_p = alg;
    }
    
    void    UserSpatial³::set_r(const Algebra&alg)
    {
        m_r = alg;
    }
    
    void    UserSpatial³::set_x(const Algebra&alg)
    {
        m_x = alg;
    }
    
    void    UserSpatial³::set_y(const Algebra&alg)
    {
        m_y = alg;
    }
    
    void    UserSpatial³::set_z(const Algebra&alg)
    {
        m_z = alg;
    }

    void    UserSpatial³::snap(UserSpatial³Snap& sn) const
    {
        Spatial³::snap(sn, m_position, m_orientation);
        sn.h    = m_h.algebra;
        sn.p    = m_p.algebra;
        sn.r    = m_r.algebra;
        sn.x    = m_x.algebra;
        sn.y    = m_y.algebra;
        sn.z    = m_z.algebra;
    }
    
    Execution       UserSpatial³::tick(const Context& ctx) 
    {
        expr::Context   u;
        u.variables[ U"t" ] = Any(ctx.time.value);
        
        m_h.tick(u);
        m_p.tick(u);
        m_r.tick(u);
        m_x.tick(u);
        m_y.tick(u);
        m_z.tick(u);
            
        m_position      = { m_x.value, m_y.value, m_z.value };
        m_orientation   = Quaternion3D(HPR, Degree(m_h.value), Degree(m_p.value), Degree(m_r.value) );
        
        mark();
        
        return {};
    }

}
