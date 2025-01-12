////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/shape/Size2.hpp>
#include <yt/os/Monitor.hpp>
#include <yt/os/MonitorBind.hpp>
#include <yt/os/MonitorData.hpp>
#include <yt/os/MonitorInfoWriter.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {

    MonitorBind::MonitorBind(const Monitor* v) : m_monitor(v ? v->id() : MonitorID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    PostAdvice    Monitor::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const MonitorBind* p = dynamic_cast<const MonitorBind*>(&pp)){
            if(p->monitor() != id())
                return REJECT;
        }
        return {};
    }
    
    Size2MM     Monitor::dimensions() const
    {
        return Size2MM( 100_mm, 100_mm );   // default is 10 cm x 10 cm
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Monitor)
