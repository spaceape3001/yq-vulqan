////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class TessellationCommand : public Command {
        YQ_OBJECT_DECLARE(TessellationCommand, Command)
    public:
    
        static void init_meta();

    protected:
        TessellationCommand(const Header&);
        TessellationCommand(const TessellationCommand&, const Header&);
        ~TessellationCommand();
        
    private:
        TessellationCommand(const TessellationCommand&) = delete;
        TessellationCommand(TessellationCommand&&) = delete;
        TessellationCommand& operator=(const TessellationCommand&) = delete;
        TessellationCommand& operator=(TessellationCommand&&) = delete;
    };
}
