////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Gamepad.hpp>
#include <tachyon/os/GamepadData.hpp>
#include <tachyon/os/GamepadInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

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

        auto wt = writer<GamepadID>();
        wt.description("Gamepad Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Gamepad>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Gamepad)
YQ_TYPE_IMPLEMENT(yq::tachyon::GamepadID)
