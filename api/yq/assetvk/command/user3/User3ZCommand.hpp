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
    class User³ZCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³ZCommand, User³Command)
    public:
    
        static void init_meta();
        User³ZCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    z() const { return m_z; }
        
    protected:
        User³ZCommand(const User³ZCommand&, const Header&);
        ~User³ZCommand();
        
    private:
        Algebra m_z;
    
        User³ZCommand(const User³ZCommand&) = delete;
        User³ZCommand(User³ZCommand&&) = delete;
        User³ZCommand& operator=(const User³ZCommand&) = delete;
        User³ZCommand& operator=(User³ZCommand&&) = delete;
    };
}
