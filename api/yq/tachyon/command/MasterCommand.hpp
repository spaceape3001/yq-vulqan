////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class MasterCommand : public Command {
        YQ_OBJECT_DECLARE(MasterCommand, Command)
    public:
    
        static void init_meta();

    protected:
        MasterCommand(const Header&);
        MasterCommand(const MasterCommand&, const Header&);
        ~MasterCommand();
        
    private:
        MasterCommand(const MasterCommand&) = delete;
        MasterCommand(MasterCommand&&) = delete;
        MasterCommand& operator=(const MasterCommand&) = delete;
        MasterCommand& operator=(MasterCommand&&) = delete;
    };
}
