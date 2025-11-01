////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QTachyonLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TachyonEvent : public Event {
        YQ_OBJECT_DECLARE(TachyonEvent, Event)
    public:
    
        static void init_meta();

    protected:
        TachyonEvent(const Header&);
        TachyonEvent(const TachyonEvent&, const Header&);
        ~TachyonEvent();
    
    private:
        TachyonEvent(const TachyonEvent&) = delete;
        TachyonEvent(TachyonEvent&&) = delete;
        TachyonEvent& operator=(const TachyonEvent&) = delete;
        TachyonEvent& operator=(TachyonEvent&&) = delete;
    };
}
