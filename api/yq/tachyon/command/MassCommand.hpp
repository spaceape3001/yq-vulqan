////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class MassCommand : public Command {
        YQ_OBJECT_DECLARE(MassCommand, Command)
    public:
    
        static void init_meta();

    protected:
        MassCommand(const Header&);
        MassCommand(const MassCommand&, const Header&);
        ~MassCommand();
        
    private:
        MassCommand(const MassCommand&) = delete;
        MassCommand(MassCommand&&) = delete;
        MassCommand& operator=(const MassCommand&) = delete;
        MassCommand& operator=(MassCommand&&) = delete;
    };
}
