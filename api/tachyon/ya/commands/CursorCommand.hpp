////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class CursorCommand : public Command {
        YQ_OBJECT_DECLARE(CursorCommand, Command)
    public:
    
        static void init_info();

    protected:
        CursorCommand(const Header&);
        CursorCommand(const CursorCommand&, const Header&);
        ~CursorCommand();
        
    private:
        CursorCommand(const CursorCommand&) = delete;
        CursorCommand(CursorCommand&&) = delete;
        CursorCommand& operator=(const CursorCommand&) = delete;
        CursorCommand& operator=(CursorCommand&&) = delete;
    };
}
