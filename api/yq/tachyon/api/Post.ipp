////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/PostMetaWriter.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/stream/Text.hpp>
#include <sstream>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Post)

namespace yq::tachyon {

    struct PostMeta::Repo {
        MetaLookup<PostMeta> posts;
    };
    
    PostMeta::Repo& PostMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    
    
    void PostMeta::sweep_all()
    {
        if(!Meta::thread_safe_write())
            return ;
        
        for(const PostMeta* p : repo().posts.all)
            const_cast<PostMeta*>(p) -> sweep();
    }

    PostMeta::PostMeta(std::string_view zName, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(zName, base, sl)
    {
        set(Flag::POST);
        repo().posts << this;
    }

    void  PostMeta::report(Stream& out) const
    {
        out << "Report for PostMeta[" << name() << "]\n";
        out << "    ID              : " << id() << "\n";
        out << "    Description     : " << description() << "\n";
        out << "    Base            : " << base()->name() << "\n";

        out << "  BASES\n";
        for(const ObjectMeta* obj : bases(ALL).all){
            out << "    " << obj->name() << "\n";
        }
        
        out << "  DERIVES\n";
        for(const ObjectMeta* obj : deriveds(ALL).all){
            out << "    " << obj->name() << "\n";
        }

        out << "  METHODS\n";
        for(const MethodMeta* obj : methods(ALL).all){
            out << "    " << obj->name() << "\n";
        }

        out << "  PROPERTIES\n";
        for(const PropertyMeta* prop : properties(ALL).all){
            out << "    " << prop->name() << "\n";
        }
    }
    
    void  PostMeta::report(const char* cat, LogPriority pri) const
    {
        std::string     text;
        {
        
            stream::Text  out(text);
            report(out);
        }
        log_category(cat).getStream(log4cpp_priority(pri)) << text;
    }

    ////////////////////////////////////////////////////////////////////////////

    std::atomic<uint64_t>    Post::s_lastId{0};

    Post::Post(const Header& h) : 
        m_id(++s_lastId), 
        m_cause(h.cause),
        m_source(h.source),
        m_target(h.target),
        m_time((h.time != time_point_t{}) ? h.time : clock_t::now())
    {
    }
    
    Post::Post(const Post&cp, const Header& h) :
        m_id(++s_lastId),
        m_cause(h.cause ? h.cause : cp.m_cause),
        m_source(h.source ? h.source : cp.m_source),
        m_target(h.target ? h.target : cp.m_target),
        m_time((h.time != time_point_t{}) ? h.time : cp.m_time)
    {
    }

    Post::~Post()
    {
    }

    bool Post::claim() const
    {
        return !m_claimed.test_and_set();
    }
    
    bool    Post::claimed() const
    {
        return m_claimed.test();
    }


    ////////////////////////////////////////////////////////////////////////////

    void Post::init_meta()
    {
        auto w = writer<Post>();
        w.description("Abstract Post Base Class");
        w.property("id", &Post::m_id).description("Post ID (do NOT assume monoticity)");
    }

    Stream& operator<<(Stream&str, const Post::Trace& i)
    {
        str << "{" << i.meta.name() << ":" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }

    std::ostringstream& operator<<(std::ostringstream&str, const Post::Trace& i)
    {
        str << "{" << i.meta.name() << ":" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }

    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&str, const Post::Trace& i)
    {
        str << "{" << i.meta.name() << ":" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }
}
