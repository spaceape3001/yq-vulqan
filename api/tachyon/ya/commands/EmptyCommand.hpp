////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Command.hpp>

namespace yq::tachyon {

    //! Test/general post type that's empty
    class EmptyCommand : public Command {
        YQ_OBJECT_DECLARE(EmptyCommand, Command)
    public:
        
        EmptyCommand(const Param&p={});
        ~EmptyCommand();
        
        static void init_info();
    };
}
