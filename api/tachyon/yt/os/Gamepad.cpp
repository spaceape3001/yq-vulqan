////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/os/Gamepad.hpp>
#include <yt/os/GamepadData.hpp>
#include <yt/os/GamepadInfoWriter.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    struct GamepadInfo::Repo {
        std::vector<const GamepadInfo*> all;
    };
    
    GamepadInfo::Repo& GamepadInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const GamepadInfo*>&    GamepadInfo::all()
    {
        return repo().all;
    }

    GamepadInfo::GamepadInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Gamepad);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Gamepad::Gamepad(const Param& p) : Tachyon(p)
    {
    }

    Gamepad::~Gamepad()
    {
    }

    void Gamepad::snap(GamepadSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Gamepad::init_info()
    {
        auto w   = writer<Gamepad>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Gamepad)
