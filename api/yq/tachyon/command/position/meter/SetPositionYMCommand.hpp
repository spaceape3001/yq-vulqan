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
    class SetPositionʸMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʸMCommand, PositionCommand)
    public:
        SetPositionʸMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʸMCommand(const SetPositionʸMCommand&, const Header&);
        ~SetPositionʸMCommand();
    private:
        Meter  m_y = 0.0;
        
        SetPositionʸMCommand(const SetPositionʸMCommand&) = delete;
        SetPositionʸMCommand(SetPositionʸMCommand&&) = delete;
        SetPositionʸMCommand& operator=(const SetPositionʸMCommand&) = delete;
        SetPositionʸMCommand& operator=(SetPositionʸMCommand&&) = delete;
    };
}
