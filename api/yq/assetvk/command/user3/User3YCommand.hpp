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
    class User³YCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³YCommand, User³Command)
    public:
    
        static void init_meta();
        User³YCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    y() const { return m_y; }
        
    protected:
        User³YCommand(const User³YCommand&, const Header&);
        ~User³YCommand();
        
    private:
        Algebra m_y;
    
        User³YCommand(const User³YCommand&) = delete;
        User³YCommand(User³YCommand&&) = delete;
        User³YCommand& operator=(const User³YCommand&) = delete;
        User³YCommand& operator=(User³YCommand&&) = delete;
    };
}
