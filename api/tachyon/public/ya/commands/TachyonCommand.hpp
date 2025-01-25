////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class TachyonCommand : public Command {
        YQ_OBJECT_DECLARE(TachyonCommand, Command)
    public:
    
        static void init_info();
    
    protected:
        TachyonCommand(const Header&);
        TachyonCommand(const TachyonCommand&, const Header&);
        ~TachyonCommand();
        
    private:
        TachyonCommand(const TachyonCommand&) = delete;
        TachyonCommand(TachyonCommand&&) = delete;
        TachyonCommand& operator=(const TachyonCommand&) = delete;
        TachyonCommand& operator=(TachyonCommand&&) = delete;
    };
}
