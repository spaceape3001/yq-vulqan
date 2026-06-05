////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's W-position
    class SetPositionʷCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʷCMCommand, PositionCommand)
    public:
        SetPositionʷCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  w() const { return m_w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʷCMCommand(const SetPositionʷCMCommand&, const Header&);
        ~SetPositionʷCMCommand();
        
    private:
        Centimeter  m_w = 0.0_m;
        
        SetPositionʷCMCommand(const SetPositionʷCMCommand&);
        SetPositionʷCMCommand(SetPositionʷCMCommand&&);
        SetPositionʷCMCommand& operator=(const SetPositionʷCMCommand&);
        SetPositionʷCMCommand& operator=(SetPositionʷCMCommand&&);
    };
}
