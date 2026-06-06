////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Physics.hpp"
#include "PhysicsData.hpp"
#include "PhysicsMetaWriter.hpp"
//#include <yq/tachyon/api/Post.hpp>

#include <yq/units.hpp>
#include <yq/meta/Init.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/app/Engine.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector3.hxx>

#ifdef NAN
    #undef NAN
#endif

namespace yq::tachyon {

    struct PhysicsMeta::Repo {
        std::vector<const PhysicsMeta*> all;
    };
    
    PhysicsMeta::Repo& PhysicsMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const PhysicsMeta*>&    PhysicsMeta::all()
    {
        return repo().all;
    }

    PhysicsMeta::PhysicsMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Flag::PHYSICS);
        set(Type::Physics);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    PhysicsSnap::PhysicsSnap()
    {
    }
    
    PhysicsSnap::~PhysicsSnap()
    {
    }

    MeterPerSecond²3D PhysicsSnap::gravity(const Meter3D& pt) const
    {
        MeterPerSecond²3D   sum = ZERO;
        for(auto& fn : gravity3){
            if(!fn)
                continue;
            MeterPerSecond²3D   g   = fn(pt);
            if(is_nan(g))
                continue;
            sum += g;
        }
        
        return sum;
    }

    const PhysicsSnap*          PhysicsSnap::parent(const Frame* frame) const
    {
        if(!TachyonSnap::parent)
            return nullptr;
        
        if(!frame)
            frame   = Frame::current();
        if(!frame)
            return nullptr;
        
        return dynamic_cast<const PhysicsSnap*>(frame->snap(TachyonSnap::parent));
    }

    MeterPerSecond3D  PhysicsSnap::wind(const Meter3D& pt) const
    {
        MeterPerSecond3D    sum = ZERO;
        for(auto& fn : wind3){
            if(!fn)
                continue;
            MeterPerSecond3D w = fn(pt);
            if(is_nan(w))
                continue;
            sum += w;
        }
        
        return sum;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Physics::Physics(const Param& p) : Tachyon(p)
    {
    }

    Physics::~Physics()
    {
    }

    void Physics::finalize(PhysicsData& d) const
    {
        Tachyon::finalize(d);
    }

    void Physics::snap(PhysicsSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Physics::init_meta()
    {
        auto w   = writer<Physics>();
        w.abstract();
        w.description("Physics");

        auto wt = writer<PhysicsID>();
        wt.description("Physics Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Physics>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Physics)
YQ_TYPE_IMPLEMENT(yq::tachyon::PhysicsID)
