////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Tristate.hpp>
#include <yq/tachyon/command/TachyonCommand.hpp>

namespace yq::tachyon {
    class SetEditModeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetEditModeCommand, TachyonCommand)
    public:
        SetEditModeCommand(const Header&, Tristate);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        Tristate edit_mode() const { return m_editMode; }

        static void init_meta();

    protected:
        SetEditModeCommand(const SetEditModeCommand&, const Header&);
        virtual ~SetEditModeCommand();
        
    private:

        Tristate m_editMode;

        SetEditModeCommand(const SetEditModeCommand&) = delete;
        SetEditModeCommand(SetEditModeCommand&&) = delete;
        SetEditModeCommand& operator=(const SetEditModeCommand&) = delete;
        SetEditModeCommand& operator=(SetEditModeCommand&&) = delete;
    };
}
