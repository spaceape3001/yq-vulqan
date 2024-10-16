////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/event.hpp>
#include <string_view>

namespace yq::tachyon {
    class EventTrigger {
    public:
        virtual std::string_view    description() const;
        virtual std::string_view    name() const;
    
        virtual bool                detect(const Event&) const = 0;

        ~EventTrigger();
        EventTrigger();
    };
}
