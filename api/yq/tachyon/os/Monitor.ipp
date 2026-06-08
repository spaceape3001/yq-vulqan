////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/MonitorData.hpp>
#include <yq/tachyon/os/MonitorMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct MonitorMeta::Repo {
        std::vector<const MonitorMeta*> all;
    };
    
    MonitorMeta::Repo& MonitorMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const MonitorMeta*>&    MonitorMeta::all()
    {
        return repo().all;
    }

    MonitorMeta::MonitorMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Type::Monitor);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    MonitorData::MonitorData()
    {
    }
    
    MonitorData::~MonitorData()
    {
    }
    
    void MonitorData::init_meta()
    {
        auto w = writer<MonitorData>();
        w.description("Monitor Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    MonitorSnap::MonitorSnap()
    {
    }
    
    MonitorSnap::~MonitorSnap()
    {
    }
    
    void MonitorSnap::init_meta()
    {
        auto w = writer<MonitorSnap>();
        w.description("Monitor Snapshot");
        //w.property("dimensions", READ_ONLY, &MonitorSnap::dimensions);
        w.property("size", READ_ONLY, &MonitorSnap::size);
        w.property("scale", READ_ONLY, &MonitorSnap::scale);
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
    
    void Monitor::init_meta()
    {
        auto w   = writer<Monitor>();
        w.abstract();
        w.description("A monitor, the thing that glows in the dark");
        w.interface<IPosition²D>();

        auto wt = writer<MonitorID>();
        wt.description("Monitor Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Monitor>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Monitor)
YQ_TYPE_IMPLEMENT(yq::tachyon::MonitorID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorSnap)
