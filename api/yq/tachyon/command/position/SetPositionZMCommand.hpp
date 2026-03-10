////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetPositionZMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionZMCommand, PositionCommand)
    public:
        SetPositionZMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionZMCommand(const SetPositionZMCommand&, const Header&);
        ~SetPositionZMCommand();
        
    private:
        Meter  m_z = 0.0;
        
        SetPositionZMCommand(const SetPositionZMCommand&) = delete;
        SetPositionZMCommand(SetPositionZMCommand&&) = delete;
        SetPositionZMCommand& operator=(const SetPositionZMCommand&) = delete;
        SetPositionZMCommand& operator=(SetPositionZMCommand&&) = delete;
    };
}
