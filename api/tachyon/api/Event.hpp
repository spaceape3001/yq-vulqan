////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TypedID.hpp>
#include <tachyon/api/Post.hpp>
#include <tachyon/typedef/event.hpp>

namespace yq::tachyon {

    class EventMeta : public PostMeta {
    public:
        template <typename C> class Writer;

        EventMeta(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };

    class Event : public Post {
        YQ_OBJECT_INFO(EventMeta)
        YQ_OBJECT_DECLARE(Event, Post)
    public:
    
        static void init_meta();
        
        struct Param {};        //< DEPRECATED
        
    protected:
        virtual ~Event();
        Event(const Param& p={});    //< DEPRECATED
        Event(const Header&);
        Event(const Event&, const Header&);
    private:
        Event(const Event&) = delete;
        Event(Event&&) = delete;
        Event& operator=(const Event&) = delete;
        Event& operator=(Event&&) = delete;
    };
}
