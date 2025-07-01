////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SceneCommand : public Command {
        YQ_OBJECT_DECLARE(SceneCommand, Command)
    public:
    
        static void init_meta();

    protected:
        SceneCommand(const Header&);
        SceneCommand(const SceneCommand&, const Header&);
        ~SceneCommand();
        
    private:
        SceneCommand(const SceneCommand&) = delete;
        SceneCommand(SceneCommand&&) = delete;
        SceneCommand& operator=(const SceneCommand&) = delete;
        SceneCommand& operator=(SceneCommand&&) = delete;
    };
}
