////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TessellationEvent : public Event {
        YQ_OBJECT_DECLARE(TessellationEvent, Event)
    public:
    
        static void init_meta();

    protected:
        TessellationEvent(const Header&);
        TessellationEvent(const TessellationEvent&, const Header&);
        ~TessellationEvent();
        
    private:
        TessellationEvent(const TessellationEvent&) = delete;
        TessellationEvent(TessellationEvent&&) = delete;
        TessellationEvent& operator=(const TessellationEvent&) = delete;
        TessellationEvent& operator=(TessellationEvent&&) = delete;
    };
}
