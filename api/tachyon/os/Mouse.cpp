////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Mouse.hpp>
#include <tachyon/os/MouseData.hpp>
#include <tachyon/os/MouseInfoWriter.hpp>
#include <tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Mouse)
YQ_TYPE_IMPLEMENT(yq::tachyon::MouseID)
