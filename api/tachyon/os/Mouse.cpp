////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Mouse.hpp>
#include <tachyon/os/MouseData.hpp>
#include <tachyon/os/MouseMetaWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct MouseMeta::Repo {
        std::vector<const MouseMeta*> all;
    };
    
    MouseMeta::Repo& MouseMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const MouseMeta*>&    MouseMeta::all()
    {
        return repo().all;
    }

    MouseMeta::MouseMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
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
        w.description("Mouse Periphial");

        auto wt = writer<MouseID>();
        wt.description("Mouse Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Mouse>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mouse)
YQ_TYPE_IMPLEMENT(yq::tachyon::MouseID)
