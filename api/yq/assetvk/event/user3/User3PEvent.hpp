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
    class User³PEvent : public User³Event {
        YQ_OBJECT_DECLARE(User³PEvent, User³Event)
    public:
    
        static void init_meta();
        User³PEvent(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    p() const { return m_p; }
        
    protected:
        User³PEvent(const User³PEvent&, const Header&);
        ~User³PEvent();
        
    private:
        Algebra m_p;
    
        User³PEvent(const User³PEvent&) = delete;
        User³PEvent(User³PEvent&&) = delete;
        User³PEvent& operator=(const User³PEvent&) = delete;
        User³PEvent& operator=(User³PEvent&&) = delete;
    };
}
