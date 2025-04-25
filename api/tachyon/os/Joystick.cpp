////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/JoystickData.hpp>
#include <tachyon/os/JoystickInfoWriter.hpp>
#include <tachyon/msg/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
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
        w.description("Joystick!");

        auto wt = writer<JoystickID>();
        wt.description("Joystick Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Joystick)
YQ_TYPE_IMPLEMENT(yq::tachyon::JoystickID)
