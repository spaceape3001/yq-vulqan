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
    class User³HEvent : public User³Event {
        YQ_OBJECT_DECLARE(User³HEvent, User³Event)
    public:
    
        static void init_meta();
        User³HEvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    h() const { return m_h; }
        
    protected:
        User³HEvent(const User³HEvent&, const Header&);
        ~User³HEvent();
        
    private:
        Algebra m_h;
    
        User³HEvent(const User³HEvent&) = delete;
        User³HEvent(User³HEvent&&) = delete;
        User³HEvent& operator=(const User³HEvent&) = delete;
        User³HEvent& operator=(User³HEvent&&) = delete;
    };
}
