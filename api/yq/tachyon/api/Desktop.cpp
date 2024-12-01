////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Desktop.hpp>
#include <yq/tachyon/api/DesktopBind.hpp>
#include <yq/tachyon/api/DesktopData.hpp>
#include <yq/tachyon/api/DesktopInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    DesktopBind::DesktopBind(const Desktop* v) : m_light(v ? v->id() : DesktopID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct DesktopInfo::Repo {
        std::vector<const DesktopInfo*> all;
    };
    
    DesktopInfo::Repo& DesktopInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const DesktopInfo*>&    DesktopInfo::all()
    {
        return repo().all;
    }

    DesktopInfo::DesktopInfo(std::string_view name, ManagerInfo& base, const std::source_location& sl) : 
        ManagerInfo(name, base, sl)
    {
        set(Type::Desktop);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Desktop::Desktop(const Param& p) : Manager(p)
    {
    }

    Desktop::~Desktop()
    {
    }


    void Desktop::snap(DesktopSnap& sn) const
    {
        Manager::snap(sn);
    }

    Manager::PostAdvice    Desktop::advise(const Post&pp) const
    {
        PostAdvice  pa  = Manager::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const DesktopBind* p = dynamic_cast<const DesktopBind*>(&pp)){
            if(p->light() != id())
                return REJECT;
        }
        return {};
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Desktop::init_info()
    {
        auto w   = writer<Desktop>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Desktop)
