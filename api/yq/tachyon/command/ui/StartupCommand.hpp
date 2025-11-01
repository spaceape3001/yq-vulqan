////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class StartupCommand : public UICommand {
        YQ_OBJECT_DECLARE(StartupCommand, UICommand)
    public:
        StartupCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        StartupCommand(const StartupCommand&, const Header&);
        virtual ~StartupCommand();
        
    private:

        StartupCommand(const StartupCommand&) = delete;
        StartupCommand(StartupCommand&&) = delete;
        StartupCommand& operator=(const StartupCommand&) = delete;
        StartupCommand& operator=(StartupCommand&&) = delete;
    };
}
