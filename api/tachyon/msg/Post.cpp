////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/msg/Post.hpp>
#include <tachyon/msg/PostInfoWriter.hpp>
#include <sstream>
#include <yt/logging.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Post)

namespace yq::tachyon {
    PostInfo::PostInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::POST);
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

    void Post::init_info()
    {
        auto w = writer<Post>();
        w.description("Abstract Post Base Class");
        w.property("id", &Post::m_id).description("Post ID (do NOT assume monoticity)");
    }

    Stream& operator<<(Stream&str, const Post::Trace& i)
    {
        str << "{id=" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }

    std::ostringstream& operator<<(std::ostringstream&str, const Post::Trace& i)
    {
        str << "{id=" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }

    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&str, const Post::Trace& i)
    {
        str << "{id=" << i.id << " source=" << i.source.id << " target=" << i.target.id << "}";
        return str;
    }
}
