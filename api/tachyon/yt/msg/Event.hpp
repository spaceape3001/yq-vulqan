////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TypedID.hpp>
#include <yt/msg/Post.hpp>
#include <tachyon/typedef/event.hpp>

namespace yq::tachyon {

    class EventInfo : public PostInfo {
    public:
        template <typename C> class Writer;

        EventInfo(std::string_view zName, PostInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class Event : public Post {
        YQ_OBJECT_INFO(EventInfo)
        YQ_OBJECT_DECLARE(Event, Post)
    public:
    
        static void init_info();
        
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
