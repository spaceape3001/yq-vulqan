////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class UnfloatCommand : public UICommand {
        YQ_OBJECT_DECLARE(UnfloatCommand, UICommand)
    public:
        UnfloatCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        UnfloatCommand(const UnfloatCommand&, const Header&);
        virtual ~UnfloatCommand();
        
    private:

        UnfloatCommand(const UnfloatCommand&) = delete;
        UnfloatCommand(UnfloatCommand&&) = delete;
        UnfloatCommand& operator=(const UnfloatCommand&) = delete;
        UnfloatCommand& operator=(UnfloatCommand&&) = delete;
    };
}
