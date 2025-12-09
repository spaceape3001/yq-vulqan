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
    class User³ZEvent : public User³Event {
        YQ_OBJECT_DECLARE(User³ZEvent, User³Event)
    public:
    
        static void init_meta();
        User³ZEvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    z() const { return m_z; }
        
    protected:
        User³ZEvent(const User³ZEvent&, const Header&);
        ~User³ZEvent();
        
    private:
        Algebra m_z;
    
        User³ZEvent(const User³ZEvent&) = delete;
        User³ZEvent(User³ZEvent&&) = delete;
        User³ZEvent& operator=(const User³ZEvent&) = delete;
        User³ZEvent& operator=(User³ZEvent&&) = delete;
    };
}
