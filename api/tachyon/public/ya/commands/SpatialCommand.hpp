////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SpatialCommand : public Command {
        YQ_OBJECT_DECLARE(SpatialCommand, Command)
    public:
    
        static void init_info();

    protected:
        SpatialCommand(const Header&);
        SpatialCommand(const SpatialCommand&, const Header&);
        ~SpatialCommand();
        
    private:
        SpatialCommand(const SpatialCommand&) = delete;
        SpatialCommand(SpatialCommand&&) = delete;
        SpatialCommand& operator=(const SpatialCommand&) = delete;
        SpatialCommand& operator=(SpatialCommand&&) = delete;
    };
}
