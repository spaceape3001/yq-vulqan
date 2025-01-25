////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class ShutdownCommand : public UICommand {
        YQ_OBJECT_DECLARE(ShutdownCommand, UICommand)
    public:
        ShutdownCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        ShutdownCommand(const ShutdownCommand&, const Header&);
        virtual ~ShutdownCommand();
        
    private:

        ShutdownCommand(const ShutdownCommand&) = delete;
        ShutdownCommand(ShutdownCommand&&) = delete;
        ShutdownCommand& operator=(const ShutdownCommand&) = delete;
        ShutdownCommand& operator=(ShutdownCommand&&) = delete;
    };
}
