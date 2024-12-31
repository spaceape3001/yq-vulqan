////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mouse.hpp"
#include <yq/tachyon/desktop/MouseBind.hpp>
#include <yq/tachyon/desktop/MouseData.hpp>
#include <yq/tachyon/desktop/MouseInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    MouseBind::MouseBind(const Mouse* v) : m_mouse(v ? v->id() : MouseID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct MouseInfo::Repo {
        std::vector<const MouseInfo*> all;
    };
    
    MouseInfo::Repo& MouseInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const MouseInfo*>&    MouseInfo::all()
    {
        return repo().all;
    }

    MouseInfo::MouseInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Mouse);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Mouse::Mouse(const Param& p) : Tachyon(p)
    {
    }

    Mouse::~Mouse()
    {
    }

    PostAdvice    Mouse::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const MouseBind* p = dynamic_cast<const MouseBind*>(&pp)){
            if(p->mouse() != id())
                return REJECT;
        }
        return {};
    }
    
    void Mouse::snap(MouseSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Mouse::init_info()
    {
        auto w   = writer<Mouse>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mouse)
