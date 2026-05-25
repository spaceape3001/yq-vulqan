////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QEngineLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class EngineEvent : public Event {
        YQ_OBJECT_DECLARE(EngineEvent, Event)
    public:
    
        static void init_meta();

    protected:
        EngineEvent(const Header&);
        EngineEvent(const EngineEvent&, const Header&);
        ~EngineEvent();
    
    private:
        EngineEvent(const EngineEvent&) = delete;
        EngineEvent(EngineEvent&&) = delete;
        EngineEvent& operator=(const EngineEvent&) = delete;
        EngineEvent& operator=(EngineEvent&&) = delete;
    };
}
