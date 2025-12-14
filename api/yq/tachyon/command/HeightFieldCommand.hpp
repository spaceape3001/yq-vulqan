////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class HeightFieldCommand : public Command {
        YQ_OBJECT_DECLARE(HeightFieldCommand, Command)
    public:
    
        static void init_meta();

    protected:
        HeightFieldCommand(const Header&);
        HeightFieldCommand(const HeightFieldCommand&, const Header&);
        ~HeightFieldCommand();
        
    private:
        HeightFieldCommand(const HeightFieldCommand&) = delete;
        HeightFieldCommand(HeightFieldCommand&&) = delete;
        HeightFieldCommand& operator=(const HeightFieldCommand&) = delete;
        HeightFieldCommand& operator=(HeightFieldCommand&&) = delete;
    };
}
