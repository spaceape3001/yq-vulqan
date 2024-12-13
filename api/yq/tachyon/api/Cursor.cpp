////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Cursor.hpp>
#include <yq/tachyon/api/CursorBind.hpp>
#include <yq/tachyon/api/CursorData.hpp>
#include <yq/tachyon/api/CursorInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    CursorBind::CursorBind(const Cursor* v) : m_cursor(v ? v->id() : CursorID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct CursorInfo::Repo {
        std::vector<const CursorInfo*> all;
    };
    
    CursorInfo::Repo& CursorInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CursorInfo*>&    CursorInfo::all()
    {
        return repo().all;
    }

    CursorInfo::CursorInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
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

    PostAdvice    Cursor::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const CursorBind* p = dynamic_cast<const CursorBind*>(&pp)){
            if(p->cursor() != id())
                return REJECT;
        }
        return {};
    }
    
    void Cursor::snap(CursorSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Cursor::init_info()
    {
        auto w   = writer<Cursor>();
        w.abstract();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Cursor)
