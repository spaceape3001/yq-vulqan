////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ShapeCommand : public Command {
        YQ_OBJECT_DECLARE(ShapeCommand, Command)
    public:
    
        static void init_info();

    protected:
        ShapeCommand(const Header&);
        ShapeCommand(const ShapeCommand&, const Header&);
        ~ShapeCommand();
        
    private:
        ShapeCommand(const ShapeCommand&) = delete;
        ShapeCommand(ShapeCommand&&) = delete;
        ShapeCommand& operator=(const ShapeCommand&) = delete;
        ShapeCommand& operator=(ShapeCommand&&) = delete;
    };
}
