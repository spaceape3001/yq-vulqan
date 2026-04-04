////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MTachyon.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/gluon/core/ustring.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/command/tachyon/SetNameCommand.hpp>
#include <yq/tachyon/command/tachyon/SetParentCommand.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MTachyon)

namespace yq::tachyon {
    struct MTachyonMeta::Repo {
        std::vector<const MTachyonMeta*>    all;
        std::map<id_t, const MTachyonMeta*> lookup;
    };
    
    MTachyonMeta::Repo& MTachyonMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    

    MTachyonMeta::MTachyonMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(zName, base, sl)
    {
        repo().all.push_back(this);
    }
    
    void    MTachyonMeta::add_managed(const TachyonMeta& tm)
    {
        repo().lookup[tm.id()]   = this;
    }

// ------------------------------------------------------------------------

    void MTachyon::init_meta()
    {
        auto w = writer<MTachyon>();
        w.description("Editing handler for a tachyon");
    }

// ------------------------------------------------------------------------

    MTachyon::MTachyon(TypedID tId) : m_otherID(tId)
    {
    }
    
    MTachyon::~MTachyon()
    {
    }

    void    MTachyon::_poll()
    {
        const Frame*  frame   = Frame::current();
        if(!frame)
            return;
        const TachyonSnap* sn   = frame->snap(m_otherID);
        if(!sn)
            return;
            
        if(sn->revision != m_otherRevision){
            m_otherRevision = sn->revision;
            emit changed();
        }
    }

    const std::vector<TypedID>&   MTachyon::ochildren() const
    {
    
        static const std::vector<TypedID> s_empty;
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return s_empty;
        return sn->children;
    }

    QString     MTachyon::oname() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return {};
        return qString(sn->name);
    }
    
    TypedID     MTachyon::oparent() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return {};
        return sn->parent;
    }
    
    bool        MTachyon::opaused() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return false;
        return sn->paused;
    }

     Tachyon*    MTachyon::opointer() const
    {
        const Frame*  frame   = Frame::current();
        if(!frame)
            return nullptr;
        return frame->object(m_otherID);
    }

    uint64_t            MTachyon::orevision() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return 0ULL;
        return sn->revision;
    }

    bool        MTachyon::orunning() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return false;
        return sn->running;
    }
    
    const TachyonSnap*  MTachyon::osnap() const
    {
        const Frame*  frame   = Frame::current();
        if(!frame)
            return nullptr;
        return frame->snap(m_otherID);
    }

    bool        MTachyon::ostarted() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return false;
        return sn->started;
    }
    
    bool        MTachyon::oteardown() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return false;
        return sn->teardown;
    }

    unit::Second MTachyon::otime() const
    {
        const TachyonSnap*  sn  = osnap();
        if(!sn)
            return 0._s;
        return sn->time;
    }

    Execution   MTachyon::paused(const Context&u) 
    {
        _poll();
        return Tachyon::paused(u);
    }
    
    void        MTachyon::setOName(const QString&s)
    {
        send(new SetNameCommand({.target=m_otherID}, sString(s)));
    }

    void        MTachyon::setOParent(TypedID tid)
    {
        send(new SetParentCommand({.target=m_otherID}, tid));
    }

    Execution   MTachyon::setup(const Context&u) 
    {
        _poll();
        return Tachyon::setup(u);
    }
    
    Execution   MTachyon::tick(const Context&u)
    {
        _poll();
        return Tachyon::tick(u);
    }
    
    Execution   MTachyon::teardown(const Context&u) 
    {
        _poll();
        return Tachyon::teardown(u);
    }
}

#include "moc_MTachyon.cpp"

