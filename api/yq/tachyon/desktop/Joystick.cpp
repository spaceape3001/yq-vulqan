////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/desktop/Joystick.hpp>
#include <yq/tachyon/desktop/JoystickBind.hpp>
#include <yq/tachyon/desktop/JoystickData.hpp>
#include <yq/tachyon/desktop/JoystickInfoWriter.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {

    JoystickBind::JoystickBind(const Joystick* v) : m_joystick(v ? v->id() : JoystickID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct JoystickInfo::Repo {
        std::vector<const JoystickInfo*> all;
    };
    
    JoystickInfo::Repo& JoystickInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const JoystickInfo*>&    JoystickInfo::all()
    {
        return repo().all;
    }

    JoystickInfo::JoystickInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Joystick);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Joystick::Joystick(const Param& p) : Tachyon(p)
    {
    }

    Joystick::~Joystick()
    {
    }

    PostAdvice    Joystick::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const JoystickBind* p = dynamic_cast<const JoystickBind*>(&pp)){
            if(p->joystick() != id())
                return REJECT;
        }
        return {};
    }

    void Joystick::snap(JoystickSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Joystick::init_info()
    {
        auto w   = writer<Joystick>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Joystick)
