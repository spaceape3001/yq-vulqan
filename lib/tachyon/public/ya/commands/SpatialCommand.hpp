////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SpatialCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SpatialCommand, TachyonCommand)
    public:
        SpatialCommand(TachyonID, const Param& p={});
        ~SpatialCommand();
    
        static void init_info();
    };
}
