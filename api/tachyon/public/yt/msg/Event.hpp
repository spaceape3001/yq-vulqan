////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Post.hpp>
#include <yt/typedef/event.hpp>

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
        
    protected:
        virtual ~Event();
        Event(const Param&);
    };
}
