////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetPositionXMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionXMCommand, PositionCommand)
    public:
        SetPositionXMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionXMCommand(const SetPositionXMCommand&, const Header&);
        ~SetPositionXMCommand();
        
    private:
        Meter  m_x = 0.0;
        
        SetPositionXMCommand(const SetPositionXMCommand&);
        SetPositionXMCommand(SetPositionXMCommand&&);
        SetPositionXMCommand& operator=(const SetPositionXMCommand&);
        SetPositionXMCommand& operator=(SetPositionXMCommand&&);
    };
}
