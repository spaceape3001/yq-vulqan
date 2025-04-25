////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Keyboard.hpp>
#include <tachyon/os/KeyboardData.hpp>
#include <tachyon/os/KeyboardInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

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
        w.description("A keyboard, the instrument to hit thy forehead on.");

        auto wt = writer<KeyboardID>();
        wt.description("Keyboard Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Keyboard)
YQ_TYPE_IMPLEMENT(yq::tachyon::KeyboardID)
