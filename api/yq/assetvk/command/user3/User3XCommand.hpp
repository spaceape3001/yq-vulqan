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
    class User³XCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³XCommand, User³Command)
    public:
    
        static void init_meta();
        User³XCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    x() const { return m_x; }
        
    protected:
        User³XCommand(const User³XCommand&, const Header&);
        ~User³XCommand();
        
    private:
        Algebra m_x;
    
        User³XCommand(const User³XCommand&) = delete;
        User³XCommand(User³XCommand&&) = delete;
        User³XCommand& operator=(const User³XCommand&) = delete;
        User³XCommand& operator=(User³XCommand&&) = delete;
    };
}
