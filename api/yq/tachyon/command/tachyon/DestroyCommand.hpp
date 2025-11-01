////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TachyonCommand.hpp>

namespace yq::tachyon {
    class DestroyCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(DestroyCommand, TachyonCommand)
    public:
        DestroyCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        DestroyCommand(const DestroyCommand&, const Header&);
        virtual ~DestroyCommand();
        
    private:

        DestroyCommand(const DestroyCommand&) = delete;
        DestroyCommand(DestroyCommand&&) = delete;
        DestroyCommand& operator=(const DestroyCommand&) = delete;
        DestroyCommand& operator=(DestroyCommand&&) = delete;
    };
}
