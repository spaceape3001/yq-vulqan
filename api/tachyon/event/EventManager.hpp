////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/app/Manager.hpp>
#include <tachyon/event/EventProducer.hpp>

namespace yq::tachyon {

    /*! \brief System level manager that can interpret/create events
    */
    class EventManager : public Manager, public EventProducer {
        YQ_OBJECT_DECLARE(EventManager, Manager)
    public:

        static void init_info();

        //! Polls to events, publishing to all
        void    poll();
        
        //! Polls to events, publishing to all *AND* the provided socket (first)
        void    poll(EventSocket&);
        virtual std::string_view    name() const override;
        virtual std::string_view    description() const;
        
    protected:
        EventManager();
        ~EventManager();
    
        /*! Actually implementation of polling
        */
        virtual void        _poll() = 0;

    private:
        void                _poll(EventSocket*);
        
        //! Guard against reentrancy to "pol"
        std::atomic_flag    m_polling;
    };
}
