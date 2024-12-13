////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Monitor.hpp>
#include <yq/tachyon/api/MonitorBind.hpp>
#include <yq/tachyon/api/MonitorData.hpp>
#include <yq/tachyon/api/MonitorInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

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
