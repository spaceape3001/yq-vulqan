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
    class SetPositionʷMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʷMCommand, PositionCommand)
    public:
        SetPositionʷMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  w() const { return m_w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʷMCommand(const SetPositionʷMCommand&, const Header&);
        ~SetPositionʷMCommand();
        
    private:
        Meter  m_w = 0.0_m;
        
        SetPositionʷMCommand(const SetPositionʷMCommand&);
        SetPositionʷMCommand(SetPositionʷMCommand&&);
        SetPositionʷMCommand& operator=(const SetPositionʷMCommand&);
        SetPositionʷMCommand& operator=(SetPositionʷMCommand&&);
    };
}
