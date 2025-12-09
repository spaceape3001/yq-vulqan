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
    class User³HCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³HCommand, User³Command)
    public:
    
        static void init_meta();
        User³HCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    h() const { return m_h; }
        
    protected:
        User³HCommand(const User³HCommand&, const Header&);
        ~User³HCommand();
        
    private:
        Algebra m_h;
    
        User³HCommand(const User³HCommand&) = delete;
        User³HCommand(User³HCommand&&) = delete;
        User³HCommand& operator=(const User³HCommand&) = delete;
        User³HCommand& operator=(User³HCommand&&) = delete;
    };
}
