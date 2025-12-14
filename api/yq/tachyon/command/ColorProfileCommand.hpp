////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ColorProfileCommand : public Command {
        YQ_OBJECT_DECLARE(ColorProfileCommand, Command)
    public:
    
        static void init_meta();

    protected:
        ColorProfileCommand(const Header&);
        ColorProfileCommand(const ColorProfileCommand&, const Header&);
        ~ColorProfileCommand();
        
    private:
        ColorProfileCommand(const ColorProfileCommand&) = delete;
        ColorProfileCommand(ColorProfileCommand&&) = delete;
        ColorProfileCommand& operator=(const ColorProfileCommand&) = delete;
        ColorProfileCommand& operator=(ColorProfileCommand&&) = delete;
    };
}
