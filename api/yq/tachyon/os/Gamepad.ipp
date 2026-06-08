////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/Gamepad.hpp>
#include <yq/tachyon/os/GamepadData.hpp>
#include <yq/tachyon/os/GamepadMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct GamepadMeta::Repo {
        std::vector<const GamepadMeta*> all;
    };
    
    GamepadMeta::Repo& GamepadMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const GamepadMeta*>&    GamepadMeta::all()
    {
        return repo().all;
    }

    GamepadMeta::GamepadMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Type::Gamepad);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    GamepadData::GamepadData() = default;
    GamepadData::~GamepadData() = default;
    
    void GamepadData::init_meta()
    {
        auto w = writer<GamepadData>();
        w.description("Gamepad Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    GamepadSnap::GamepadSnap() = default;
    GamepadSnap::~GamepadSnap() = default;
    
    void GamepadSnap::init_meta()
    {
        auto w = writer<GamepadSnap>();
        w.description("Gamepad Snapshot");
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
    
    void Gamepad::init_meta()
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
YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadSnap)
