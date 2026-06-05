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
    class SetPositionʸCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʸCMCommand, PositionCommand)
    public:
        SetPositionʸCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʸCMCommand(const SetPositionʸCMCommand&, const Header&);
        ~SetPositionʸCMCommand();
    private:
        Centimeter  m_y = 0.0;
        
        SetPositionʸCMCommand(const SetPositionʸCMCommand&) = delete;
        SetPositionʸCMCommand(SetPositionʸCMCommand&&) = delete;
        SetPositionʸCMCommand& operator=(const SetPositionʸCMCommand&) = delete;
        SetPositionʸCMCommand& operator=(SetPositionʸCMCommand&&) = delete;
    };
}
