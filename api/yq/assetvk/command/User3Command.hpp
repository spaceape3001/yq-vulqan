////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class User³Command : public SpatialCommand {
        YQ_OBJECT_DECLARE(User³Command, SpatialCommand)
    public:
    
        static void init_meta();

    protected:
        User³Command(const Header&);
        User³Command(const User³Command&, const Header&);
        ~User³Command();
        
    private:
        User³Command(const User³Command&) = delete;
        User³Command(User³Command&&) = delete;
        User³Command& operator=(const User³Command&) = delete;
        User³Command& operator=(User³Command&&) = delete;
    };
}
