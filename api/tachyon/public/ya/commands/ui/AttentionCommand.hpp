////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class AttentionCommand : public UICommand {
        YQ_OBJECT_DECLARE(AttentionCommand, UICommand)
    public:
        AttentionCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        AttentionCommand(const AttentionCommand&, const Header&);
        virtual ~AttentionCommand();
        
    private:

        AttentionCommand(const AttentionCommand&) = delete;
        AttentionCommand(AttentionCommand&&) = delete;
        AttentionCommand& operator=(const AttentionCommand&) = delete;
        AttentionCommand& operator=(AttentionCommand&&) = delete;
    };
}
