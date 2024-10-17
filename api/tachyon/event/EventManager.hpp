////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/app/Manager.hpp>
#include <tachyon/event/EventProducer.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {

    /*! \brief System level manager that can interpret/create events
    */
    class EventManager : public Manager, public EventProducer {
        YQ_OBJECT_DECLARE(EventManager, Manager)
    public:

        static void init_info();

        /*! \brief Polls for events
        
            This polls the manager to generate events.  If greater than 
            zero, then the timeout is a SUGGESTION to wait, the specific
            manager is free to ignore this!
        
            \note WARNING, the timeout might not be honored/supported
            
            \param[in] timeout Maximum duration to "wait" for events
        */
        void    poll(unit::Second timeout=Second(0));

        //! Polls to events, publishing to all *AND* the provided socket (first)
        void    poll(EventSocket&, unit::Second timeout=Second(0));
        virtual std::string_view    name() const override;
        virtual std::string_view    description() const;
        
    protected:
        EventManager();
        ~EventManager();
    
        /*! Actually implementation of polling
        */
        virtual void        _poll(unit::Second) = 0;

    private:
        void                _poll(EventSocket*, unit::Second);
        
        //! Guard against reentrancy to "pol"
        std::atomic_flag    m_polling;
    };
}
