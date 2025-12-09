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
    class User³REvent : public User³Event {
        YQ_OBJECT_DECLARE(User³REvent, User³Event)
    public:
    
        static void init_meta();
        User³REvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    r() const { return m_r; }
        
    protected:
        User³REvent(const User³REvent&, const Header&);
        ~User³REvent();
        
    private:
        Algebra m_r;
    
        User³REvent(const User³REvent&) = delete;
        User³REvent(User³REvent&&) = delete;
        User³REvent& operator=(const User³REvent&) = delete;
        User³REvent& operator=(User³REvent&&) = delete;
    };
}
