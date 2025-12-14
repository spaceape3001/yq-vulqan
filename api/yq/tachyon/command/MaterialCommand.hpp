////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class MaterialCommand : public Command {
        YQ_OBJECT_DECLARE(MaterialCommand, Command)
    public:
    
        static void init_meta();

    protected:
        MaterialCommand(const Header&);
        MaterialCommand(const MaterialCommand&, const Header&);
        ~MaterialCommand();
        
    private:
        MaterialCommand(const MaterialCommand&) = delete;
        MaterialCommand(MaterialCommand&&) = delete;
        MaterialCommand& operator=(const MaterialCommand&) = delete;
        MaterialCommand& operator=(MaterialCommand&&) = delete;
    };
}
