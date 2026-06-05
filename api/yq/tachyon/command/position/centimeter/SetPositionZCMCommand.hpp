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
    class SetPositionᶻCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻCMCommand, PositionCommand)
    public:
        SetPositionᶻCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionᶻCMCommand(const SetPositionᶻCMCommand&, const Header&);
        ~SetPositionᶻCMCommand();
        
    private:
        Centimeter  m_z = 0.0;
        
        SetPositionᶻCMCommand(const SetPositionᶻCMCommand&) = delete;
        SetPositionᶻCMCommand(SetPositionᶻCMCommand&&) = delete;
        SetPositionᶻCMCommand& operator=(const SetPositionᶻCMCommand&) = delete;
        SetPositionᶻCMCommand& operator=(SetPositionᶻCMCommand&&) = delete;
    };
}
