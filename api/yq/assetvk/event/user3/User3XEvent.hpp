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
    class User³XEvent : public User³Event {
        YQ_OBJECT_DECLARE(User³XEvent, User³Event)
    public:
    
        static void init_meta();
        User³XEvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    x() const { return m_x; }
        
    protected:
        User³XEvent(const User³XEvent&, const Header&);
        ~User³XEvent();
        
    private:
        Algebra m_x;
    
        User³XEvent(const User³XEvent&) = delete;
        User³XEvent(User³XEvent&&) = delete;
        User³XEvent& operator=(const User³XEvent&) = delete;
        User³XEvent& operator=(User³XEvent&&) = delete;
    };
}
