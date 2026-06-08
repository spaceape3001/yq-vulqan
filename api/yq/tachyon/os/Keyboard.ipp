////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/Keyboard.hpp>
#include <yq/tachyon/os/KeyboardData.hpp>
#include <yq/tachyon/os/KeyboardMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct KeyboardMeta::Repo {
        std::vector<const KeyboardMeta*> all;
    };
    
    KeyboardMeta::Repo& KeyboardMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const KeyboardMeta*>&    KeyboardMeta::all()
    {
        return repo().all;
    }

    KeyboardMeta::KeyboardMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Type::Keyboard);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    KeyboardData::KeyboardData() = default;
    KeyboardData::~KeyboardData() = default;

    void KeyboardData::init_meta()
    {
        auto w = writer<KeyboardData>();
        w.description("Keyboard Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    KeyboardSnap::KeyboardSnap() = default;
    KeyboardSnap::~KeyboardSnap() = default;

    void KeyboardSnap::init_meta()
    {
        auto w = writer<KeyboardSnap>();
        w.description("Keyboard Snapshot");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Keyboard::Keyboard(const Param& p) : Tachyon(p)
    {
    }

    Keyboard::~Keyboard()
    {
    }

    void Keyboard::snap(KeyboardSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Keyboard::init_meta()
    {
        auto w   = writer<Keyboard>();
        w.abstract();
        w.description("A keyboard, the instrument to hit thy forehead on.");

        auto wt = writer<KeyboardID>();
        wt.description("Keyboard Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Keyboard>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Keyboard)
YQ_TYPE_IMPLEMENT(yq::tachyon::KeyboardID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardSnap)
