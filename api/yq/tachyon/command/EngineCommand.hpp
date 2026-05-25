////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class EngineCommand : public Command {
        YQ_OBJECT_DECLARE(EngineCommand, Command)
    public:
    
        static void init_meta();

    protected:
        EngineCommand(const Header&);
        EngineCommand(const EngineCommand&, const Header&);
        ~EngineCommand();
        
    private:
        EngineCommand(const EngineCommand&) = delete;
        EngineCommand(EngineCommand&&) = delete;
        EngineCommand& operator=(const EngineCommand&) = delete;
        EngineCommand& operator=(EngineCommand&&) = delete;
    };
}
