////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/command/User3Command.hpp>
#include <yq/userexpr/Algebra.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class User³RCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³RCommand, User³Command)
    public:
    
        static void init_meta();
        User³RCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    r() const { return m_r; }
        
    protected:
        User³RCommand(const User³RCommand&, const Header&);
        ~User³RCommand();
        
    private:
        Algebra m_r;
    
        User³RCommand(const User³RCommand&) = delete;
        User³RCommand(User³RCommand&&) = delete;
        User³RCommand& operator=(const User³RCommand&) = delete;
        User³RCommand& operator=(User³RCommand&&) = delete;
    };
}
