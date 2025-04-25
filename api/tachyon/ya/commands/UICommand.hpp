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
    class UICommand : public Command {
        YQ_OBJECT_DECLARE(UICommand, Command)
    public:
    
        static void init_info();

    protected:
        UICommand(const Header&);
        UICommand(const UICommand&, const Header&);
        ~UICommand();
        
    private:
        UICommand(const UICommand&) = delete;
        UICommand(UICommand&&) = delete;
        UICommand& operator=(const UICommand&) = delete;
        UICommand& operator=(UICommand&&) = delete;
    };
}
