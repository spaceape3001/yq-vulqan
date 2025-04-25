////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <tachyon/typedef/post.hpp>
#include <tachyon/api/TypedID.hpp>
#include <atomic>
#include <chrono>

namespace log4cpp { class CategoryStream; }

namespace yq::tachyon {
    class PostInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        PostInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    /*! \brief Light weight message, which can be an event, an input, a command, a request, etc.
    
        The post is supposed to be light weight, used to courier to another 
        listener via the mailer.
    */
    class Post : public Object, public RefCount {
        YQ_OBJECT_INFO(PostInfo)
        YQ_OBJECT_DECLARE(Post, Object)
    public:
    
        //! Use this to make a property listable by the logger box
        static constexpr const int kTag_Log     = 2000;
        
        //! Use this to capture state-save-data
        static constexpr const int kTag_Save    = 2001;
    
        using clock_t  = std::chrono::high_resolution_clock;
    
        //! Our time point
        using time_point_t  = clock_t::time_point;
        
        //! Time of message creation
        const time_point_t& time() const { return m_time; }
        
        struct Header {
            PostCPtr        cause;
            TypedID         source;
            TypedID         target;
            time_point_t    time;       //< If set, overrides the system/copy time
        };
        
        struct Trace {
            TypedID         source;
            TypedID         target;
            uint64_t        id;
        };
    
        //! Post identifier (executable-unique)
        PostID  id() const { return { m_id }; }
        
        static void init_info();
        
        //! Allows for a new post with the specified "bind" ID
        //! \note This can return NULL if not valid or not implemented for that post type
        virtual PostCPtr    clone(rebind_k, const Header&) const { return {}; }

        //! Target of the post (command, to, etc)
        //! Note, empty target means "everybody with interest" (ie, events)
        const TypedID&      target() const { return m_target; }
        
        //! Source of the post (event, from, etc) -- try to be honest :)
        const TypedID&      source() const { return m_source; }
        
        const PostCPtr&     cause() const { return m_cause; }
        
        bool    claim() const;
        bool    claimed() const;
        
        Trace       trace() const { return { m_source, m_target, m_id }; }
        
    protected:
        //! Constructs a post
        Post(const Header&);
        
        //! Copies the timestamp (ID will be new), allowing for parametric overrides
        Post(const Post&, const Header&);
        virtual ~Post();
        
    private:
        friend class Tachyon;
    
        const uint64_t              m_id;
        PostCPtr                    m_cause;
        TypedID                     m_source;
        TypedID                     m_target;
        time_point_t                m_time;
        mutable std::atomic_flag    m_claimed;
        
        Post(const Post&) = delete;
        Post(Post&&) = delete;
        Post& operator=(const Post&) = delete;
        Post& operator=(Post&&) = delete;
        
        static std::atomic<uint64_t>    s_lastId;
    };

    Stream& operator<<(Stream&, const Post::Trace&);
    std::ostringstream& operator<<(std::ostringstream&, const Post::Trace&);
    log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const Post::Trace&);
}

