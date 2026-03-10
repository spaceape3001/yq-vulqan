////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetPositionYMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionYMCommand, PositionCommand)
    public:
        SetPositionYMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionYMCommand(const SetPositionYMCommand&, const Header&);
        ~SetPositionYMCommand();
    private:
        Meter  m_y = 0.0;
        
        SetPositionYMCommand(const SetPositionYMCommand&) = delete;
        SetPositionYMCommand(SetPositionYMCommand&&) = delete;
        SetPositionYMCommand& operator=(const SetPositionYMCommand&) = delete;
        SetPositionYMCommand& operator=(SetPositionYMCommand&&) = delete;
    };
}
