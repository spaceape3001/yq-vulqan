////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tachyon.hpp"
#include "TachyonBind.hpp"
#include "TachyonInfoWriter.hpp"
#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    TachyonInfo::TachyonInfo(std::string_view zName, post::PBXInfo& base, const std::source_location& sl) :
        post::PBXInfo(zName, base, sl)
    {
        set(Flag::TACHYON);
    }

    Tachyon::Tachyon(const Param& p) : Tachyon(p, INIT)
    {
        //  Add to thread...
    }
    
    Tachyon::Tachyon(const Param&p, init_t) : post::PBX(p)
    {
        m_threadId  = thread::id();
    }

    Tachyon::Tachyon(const Param& p, thread_t) : Tachyon(p, INIT)
    {
    }

    Tachyon::~Tachyon()
    {
    }
    
    bool Tachyon::in_thread() const
    {
        return m_threadId == thread::id();
    }

    void    Tachyon::receive(const post::PostCPtr& pp) 
    {
        if(!pp)
            return ;
        
        if(m_replay && in_thread()){
            post::PBX::receive(pp);
            return;
        }
            
        if(const TachyonBind* p = dynamic_cast<const TachyonBind*>(pp.ptr())){
            if(p->tachyon() != this)
                return ;
        }

        switch(m_postMode){
        case PostMode::Direct:
            post::PBX::receive(pp);
            break;
        case PostMode::ThreadSafe:
            if(in_thread()){
                post::PBX::receive(pp);
            } else {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        case PostMode::Queued:
            if(in_thread()){
                m_direct.push_back(pp);
            } else {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        case PostMode::OneQueue:
            {
                XLOCK
                m_threaded.push_back(pp);
            }
            break;
        }
    }

    void    Tachyon::_replay(direct_t)
    {
        std::vector<post::PostCPtr> posts;
        std::swap(posts, m_direct);
        for(const post::PostCPtr& p : posts)
            receive(p);
    }
    
    void    Tachyon::_replay(thread_t)
    {
        std::vector<post::PostCPtr> posts;
        {
            XLOCK
            std::swap(posts, m_threaded);
        }
        for(const post::PostCPtr& p : posts)
            receive(p);
    }

    bool    Tachyon::in_replay() const
    {
        return in_thread() && m_replay;
    }
    
    void    Tachyon::replay(direct_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(DIRECT);
        m_replay  = false;
    }

    void    Tachyon::replay(thread_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(THREAD);
        m_replay  = false;
    }
    
    void    Tachyon::replay(all_t)
    {
        if(m_replay)
            return ;
        m_replay  = true;
        _replay(DIRECT);
        _replay(THREAD);
        m_replay  = false;
    }

    void    Tachyon::set_post_mode(PostMode pm)
    {
        m_postMode      = pm;
    }

    void Tachyon::init_info()
    {
        auto w = writer<Tachyon>();
        w.description("Tachyon abstract base class");
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tachyon)
