////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/core/Object.hpp>
#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/tachyon/typedef/event.hpp>
#include <atomic>
#include <chrono>
#include <concepts>

namespace yq::tachyon {
    class EventInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        EventInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    
//        bool        dispatchable() const { return m_dispatchable; }
    
    private:
//        bool        m_dispatchable  = false;
    };

    /*! \brief Something happens
    
        An event is something that happens/commanded (ie, inputs, triggers, windows, etc).
        
        EventProducer is something that can generate events (ie GLFW)
        
        EventSocket is something that can receive events
        
        EventMapper is something that translates between events (ie maps "spacebar" to "a jump command")
        
        EventFrame is a collection of events (and its technically an event socket)
    */
    class Event : public Object, public RefCount {
        YQ_OBJECT_INFO(EventInfo)
        YQ_OBJECT_DECLARE(Event, Object)
    public:
    
        enum class Flag : uint8_t {
            ImGui       = 0
        };
        
        using flags_t       = Flags<Flag>;
        
        struct Param {
            flags_t          flags = {};
        };
    
    
        using time_point_t  = std::chrono::high_resolution_clock::time_point;
    
        bool    is_command() const;
        bool    is_input() const;
    
        virtual ~Event();
        
        void    dispatch();

        // Invalid reference until published
        EventProducer&      originator() const { return *m_originator; }
        
        //! TRUE if somebody's "dealt" with the event
        bool                handled() const;
        
        //! 
        bool                published() const { return static_cast<bool>(m_originator); }
        
        //! Marks the event as handled (unconditional)
        bool                mark();
        
        //! Resets the event handled flag
        void                reset();
        
        const time_point_t& time() const { return m_time; }
        const uint64_t      id() const { return m_id; }
        
        flags_t             flags() const { return m_flags; }
        
        bool                is_imgui() const;
        

    protected:

        Event(const Param&);

        /*! \brief Invokes the event's handler
        
            \note DURING this call, this event will be marked as "handled".  This will be cleared if it returns false.
            \return TRUE to indicate success, FALSE will clear the handled flag
        */
        virtual bool    _dispatch();
        
        void            set_flag(Flag);
        
    private:
        friend class EventProducer;
        
        const uint64_t      m_id;
        const time_point_t  m_time;
        flags_t             m_flags;
        EventProducer*      m_originator    = nullptr;
        std::atomic_flag    m_handled;
        
        static std::atomic<uint64_t>    s_lastId;
    };
    
    template <typename E>
    concept SomeEvent = std::derived_from<E, Event>;
}
