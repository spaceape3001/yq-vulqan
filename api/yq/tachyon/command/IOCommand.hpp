////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class IOCommand : public Command {
        YQ_OBJECT_DECLARE(IOCommand, Command)
    public:
    
        static void init_meta();

    protected:
        IOCommand(const Header&);
        IOCommand(const IOCommand&, const Header&);
        ~IOCommand();
        
    private:
        IOCommand(const IOCommand&) = delete;
        IOCommand(IOCommand&&) = delete;
        IOCommand& operator=(const IOCommand&) = delete;
        IOCommand& operator=(IOCommand&&) = delete;
    };
}
