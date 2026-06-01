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
    class SetPositionᶻMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻMCommand, PositionCommand)
    public:
        SetPositionᶻMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionᶻMCommand(const SetPositionᶻMCommand&, const Header&);
        ~SetPositionᶻMCommand();
        
    private:
        Meter  m_z = 0.0;
        
        SetPositionᶻMCommand(const SetPositionᶻMCommand&) = delete;
        SetPositionᶻMCommand(SetPositionᶻMCommand&&) = delete;
        SetPositionᶻMCommand& operator=(const SetPositionᶻMCommand&) = delete;
        SetPositionᶻMCommand& operator=(SetPositionᶻMCommand&&) = delete;
    };
}
