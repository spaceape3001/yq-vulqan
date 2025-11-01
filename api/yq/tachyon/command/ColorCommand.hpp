////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ColorCommand : public Command {
        YQ_OBJECT_DECLARE(ColorCommand, Command)
    public:
    
        static void init_meta();

    protected:
        ColorCommand(const Header&);
        ColorCommand(const ColorCommand&, const Header&);
        ~ColorCommand();
        
    private:
        ColorCommand(const ColorCommand&) = delete;
        ColorCommand(ColorCommand&&) = delete;
        ColorCommand& operator=(const ColorCommand&) = delete;
        ColorCommand& operator=(ColorCommand&&) = delete;
    };
}
