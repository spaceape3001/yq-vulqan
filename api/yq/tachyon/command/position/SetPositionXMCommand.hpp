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
    class SetPositionˣMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionˣMCommand, PositionCommand)
    public:
        SetPositionˣMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionˣMCommand(const SetPositionˣMCommand&, const Header&);
        ~SetPositionˣMCommand();
        
    private:
        Meter  m_x = 0.0;
        
        SetPositionˣMCommand(const SetPositionˣMCommand&);
        SetPositionˣMCommand(SetPositionˣMCommand&&);
        SetPositionˣMCommand& operator=(const SetPositionˣMCommand&);
        SetPositionˣMCommand& operator=(SetPositionˣMCommand&&);
    };
}
