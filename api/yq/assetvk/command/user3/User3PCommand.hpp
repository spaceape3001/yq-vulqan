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
    class User³PCommand : public User³Command {
        YQ_OBJECT_DECLARE(User³PCommand, User³Command)
    public:
    
        static void init_meta();
        User³PCommand(const Header&, const Algebra&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Algebra&    p() const { return m_p; }
        
    protected:
        User³PCommand(const User³PCommand&, const Header&);
        ~User³PCommand();
        
    private:
        Algebra m_p;
    
        User³PCommand(const User³PCommand&) = delete;
        User³PCommand(User³PCommand&&) = delete;
        User³PCommand& operator=(const User³PCommand&) = delete;
        User³PCommand& operator=(User³PCommand&&) = delete;
    };
}
