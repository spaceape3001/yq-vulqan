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
    class SetPositionˣCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionˣCMCommand, PositionCommand)
    public:
        SetPositionˣCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionˣCMCommand(const SetPositionˣCMCommand&, const Header&);
        ~SetPositionˣCMCommand();
        
    private:
        Centimeter  m_x = 0.0;
        
        SetPositionˣCMCommand(const SetPositionˣCMCommand&);
        SetPositionˣCMCommand(SetPositionˣCMCommand&&);
        SetPositionˣCMCommand& operator=(const SetPositionˣCMCommand&);
        SetPositionˣCMCommand& operator=(SetPositionˣCMCommand&&);
    };
}
