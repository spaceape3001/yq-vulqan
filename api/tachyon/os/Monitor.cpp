////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/shape/Size2.hpp>
#include <tachyon/os/Monitor.hpp>
#include <tachyon/os/MonitorData.hpp>
#include <tachyon/os/MonitorInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct MonitorInfo::Repo {
        std::vector<const MonitorInfo*> all;
    };
    
    MonitorInfo::Repo& MonitorInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const MonitorInfo*>&    MonitorInfo::all()
    {
        return repo().all;
    }

    MonitorInfo::MonitorInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Monitor);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Monitor::Monitor(const Param& p) : Tachyon(p)
    {
    }

    Monitor::~Monitor()
    {
    }

    Size2MM     Monitor::dimensions() const
    {
        return Size2MM( 100_mm, 100_mm );   // default is 10 cm x 10 cm
    }

    Vector2D    Monitor::position() const
    {
        return Vector2D(0., 0.);
    }
    
    Vector2F    Monitor::scale() const
    {
        return Vector2F(1.f, 1.f);
    }
    
    Size2D      Monitor::size() const
    {
        return Size2D( 1024, 768 ); // suitable default
    }

    void Monitor::snap(MonitorSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Monitor::init_info()
    {
        auto w   = writer<Monitor>();
        w.abstract();
        w.description("A monitor, the thing that glows in the dark");

        auto wt = writer<MonitorID>();
        wt.description("Monitor Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Monitor>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Monitor)
YQ_TYPE_IMPLEMENT(yq::tachyon::MonitorID)
