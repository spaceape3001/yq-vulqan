////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class HideCommand : public UICommand {
        YQ_OBJECT_DECLARE(HideCommand, UICommand)
    public:
        HideCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        HideCommand(const HideCommand&, const Header&);
        virtual ~HideCommand();
        
    private:

        HideCommand(const HideCommand&) = delete;
        HideCommand(HideCommand&&) = delete;
        HideCommand& operator=(const HideCommand&) = delete;
        HideCommand& operator=(HideCommand&&) = delete;
    };
}
