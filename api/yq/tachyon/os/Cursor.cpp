////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/os/CursorData.hpp>
#include <yq/tachyon/os/CursorMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct CursorMeta::Repo {
        std::vector<const CursorMeta*> all;
    };
    
    CursorMeta::Repo& CursorMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CursorMeta*>&    CursorMeta::all()
    {
        return repo().all;
    }

    CursorMeta::CursorMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Type::Cursor);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Cursor::Cursor(const Param& p) : Tachyon(p)
    {
    }

    Cursor::~Cursor()
    {
    }

    void Cursor::snap(CursorSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Cursor::init_meta()
    {
        auto w   = writer<Cursor>();
        w.abstract();
        w.description("Cursor, thing that can spin");

        auto wt = writer<CursorID>();
        wt.description("Cursor Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Cursor>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Cursor)
YQ_TYPE_IMPLEMENT(yq::tachyon::CursorID)
