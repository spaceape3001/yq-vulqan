////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/assetvk/event/Circular3Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³PeriodEvent : public Circular³Event {
        YQ_OBJECT_DECLARE(Circular³PeriodEvent, Circular³Event)
    public:
    
        static void init_meta();
        Circular³PeriodEvent(const Header&, unit::Second);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        unit::Second    period() const { return m_period; }
        
    protected:
        Circular³PeriodEvent(const Circular³PeriodEvent&, const Header&);
        ~Circular³PeriodEvent();
        
    private:
        unit::Second    m_period;
    
        Circular³PeriodEvent(const Circular³PeriodEvent&) = delete;
        Circular³PeriodEvent(Circular³PeriodEvent&&) = delete;
        Circular³PeriodEvent& operator=(const Circular³PeriodEvent&) = delete;
        Circular³PeriodEvent& operator=(Circular³PeriodEvent&&) = delete;
    };
}
