////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/Post.hpp>
#include <yt/PostInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Post)

namespace yq::tachyon {
    PostInfo::PostInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::POST);
    }

    ////////////////////////////////////////////////////////////////////////////

    std::atomic<uint64_t>    Post::s_lastId{0};

    Post::Post(const Param&) : 
        m_id(++s_lastId), 
        m_time(clock_t::now())
    {
    }
    
    Post::~Post()
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    void Post::init_info()
    {
        auto w = writer<Post>();
        w.description("Abstract Post Base Class");
        w.property("id", &Post::id).description("Post ID (do NOT assume monoticity)");
    }
}
