////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ControllerCommand.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class SetTargetCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(SetTargetCommand, ControllerCommand)
    public:

        SetTargetCommand(const Header&, TypedID);
        
        TypedID    target() const { return m_target; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        SetTargetCommand(const SetTargetCommand&, const Header&);
        virtual ~SetTargetCommand();
        
    private:
        TypedID const  m_target;
        
        SetTargetCommand(const SetTargetCommand&) = delete;
        SetTargetCommand(SetTargetCommand&&) = delete;
        SetTargetCommand& operator=(const SetTargetCommand&) = delete;
        SetTargetCommand& operator=(SetTargetCommand&&) = delete;
    };
}
