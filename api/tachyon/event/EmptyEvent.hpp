////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyEvent : public Event {
        YQ_OBJECT_DECLARE(EmptyEvent, Event)
    public:
        
        EmptyEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();

    protected:

        EmptyEvent(const EmptyEvent&, const Header&);
        ~EmptyEvent();
        
    private:
        EmptyEvent(const EmptyEvent&) = delete;
        EmptyEvent(EmptyEvent&&) = delete;
        EmptyEvent& operator=(const EmptyEvent&) = delete;
        EmptyEvent& operator=(EmptyEvent&&) = delete;
    };
}
