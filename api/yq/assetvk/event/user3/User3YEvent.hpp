////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/event/User3Event.hpp>
#include <yq/userexpr/Algebra.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class User³YEvent : public User³Event {
        YQ_OBJECT_DECLARE(User³YEvent, User³Event)
    public:
    
        static void init_meta();
        User³YEvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    y() const { return m_y; }
        
    protected:
        User³YEvent(const User³YEvent&, const Header&);
        ~User³YEvent();
        
    private:
        Algebra m_y;
    
        User³YEvent(const User³YEvent&) = delete;
        User³YEvent(User³YEvent&&) = delete;
        User³YEvent& operator=(const User³YEvent&) = delete;
        User³YEvent& operator=(User³YEvent&&) = delete;
    };
}
