////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class PositionCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition², TachyonCommand)
    public:
        PositionCommand(TachyonID, const const Param& p={});
        ~PositionCommand();
    
        static void init_info();
    };
}
