////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class CloseCommand : public UICommand {
        YQ_OBJECT_DECLARE(CloseCommand, UICommand)
    public:
        CloseCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        CloseCommand(const CloseCommand&, const Header&);
        virtual ~CloseCommand();
        
    private:

        CloseCommand(const CloseCommand&) = delete;
        CloseCommand(CloseCommand&&) = delete;
        CloseCommand& operator=(const CloseCommand&) = delete;
        CloseCommand& operator=(CloseCommand&&) = delete;
    };
}
