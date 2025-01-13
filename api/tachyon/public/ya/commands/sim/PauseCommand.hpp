////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SimCommand.hpp>

namespace yq::tachyon {
    class PauseCommand : public SimCommand {
        YQ_OBJECT_DECLARE(PauseCommand, SimCommand)
    public:
        PauseCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        PauseCommand(const PauseCommand&, const Header&);
        virtual ~PauseCommand();
        
    private:

        PauseCommand(const PauseCommand&) = delete;
        PauseCommand(PauseCommand&&) = delete;
        PauseCommand& operator=(const PauseCommand&) = delete;
        PauseCommand& operator=(PauseCommand&&) = delete;
    };
}
