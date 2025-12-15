////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class RangeCommand : public Command {
        YQ_OBJECT_DECLARE(RangeCommand, Command)
    public:
    
        static void init_meta();

    protected:
        RangeCommand(const Header&);
        RangeCommand(const RangeCommand&, const Header&);
        ~RangeCommand();
        
    private:
        RangeCommand(const RangeCommand&) = delete;
        RangeCommand(RangeCommand&&) = delete;
        RangeCommand& operator=(const RangeCommand&) = delete;
        RangeCommand& operator=(RangeCommand&&) = delete;
    };
}
