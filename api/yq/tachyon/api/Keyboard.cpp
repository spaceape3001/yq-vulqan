////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Keyboard.hpp>
#include <yq/tachyon/api/KeyboardBind.hpp>
#include <yq/tachyon/api/KeyboardData.hpp>
#include <yq/tachyon/api/KeyboardInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    KeyboardBind::KeyboardBind(const Keyboard* v) : m_keyboard(v ? v->id() : KeyboardID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct KeyboardInfo::Repo {
        std::vector<const KeyboardInfo*> all;
    };
    
    KeyboardInfo::Repo& KeyboardInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const KeyboardInfo*>&    KeyboardInfo::all()
    {
        return repo().all;
    }

    KeyboardInfo::KeyboardInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Keyboard);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Keyboard::Keyboard(const Param& p) : Tachyon(p)
    {
    }

    Keyboard::~Keyboard()
    {
    }

    PostAdvice    Keyboard::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const KeyboardBind* p = dynamic_cast<const KeyboardBind*>(&pp)){
            if(p->keyboard() != id())
                return REJECT;
        }
        return {};
    }
    
    void Keyboard::snap(KeyboardSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Keyboard::init_info()
    {
        auto w   = writer<Keyboard>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Keyboard)
