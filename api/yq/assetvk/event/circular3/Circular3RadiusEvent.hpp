////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/event/Circular3Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³RadiusEvent : public Circular³Event {
        YQ_OBJECT_DECLARE(Circular³RadiusEvent, Circular³Event)
    public:
    
        static void init_meta();
        Circular³RadiusEvent(const Header&, double);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        double    radius() const { return m_radius; }
        
    protected:
        Circular³RadiusEvent(const Circular³RadiusEvent&, const Header&);
        ~Circular³RadiusEvent();
        
    private:
        double    m_radius;
    
        Circular³RadiusEvent(const Circular³RadiusEvent&) = delete;
        Circular³RadiusEvent(Circular³RadiusEvent&&) = delete;
        Circular³RadiusEvent& operator=(const Circular³RadiusEvent&) = delete;
        Circular³RadiusEvent& operator=(Circular³RadiusEvent&&) = delete;
    };
}
