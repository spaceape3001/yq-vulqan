////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TextureCommand : public Command {
        YQ_OBJECT_DECLARE(TextureCommand, Command)
    public:
    
        static void init_meta();

    protected:
        TextureCommand(const Header&);
        TextureCommand(const TextureCommand&, const Header&);
        ~TextureCommand();
        
    private:
        TextureCommand(const TextureCommand&) = delete;
        TextureCommand(TextureCommand&&) = delete;
        TextureCommand& operator=(const TextureCommand&) = delete;
        TextureCommand& operator=(TextureCommand&&) = delete;
    };
}
