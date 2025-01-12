////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class FocusCommand : public UICommand {
        YQ_OBJECT_DECLARE(FocusCommand, UICommand)
    public:
        FocusCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        FocusCommand(const FocusCommand&, const Header&);
        virtual ~FocusCommand();
        
    private:

        FocusCommand(const FocusCommand&) = delete;
        FocusCommand(FocusCommand&&) = delete;
        FocusCommand& operator=(const FocusCommand&) = delete;
        FocusCommand& operator=(FocusCommand&&) = delete;
    };
}
