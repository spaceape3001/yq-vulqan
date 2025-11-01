////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetPositionᶻCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻCommand, PositionCommand)
    public:
        SetPositionᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionᶻCommand(const SetPositionᶻCommand&, const Header&);
        ~SetPositionᶻCommand();
        
    private:
        double  m_z = 0.0;
        
        SetPositionᶻCommand(const SetPositionᶻCommand&) = delete;
        SetPositionᶻCommand(SetPositionᶻCommand&&) = delete;
        SetPositionᶻCommand& operator=(const SetPositionᶻCommand&) = delete;
        SetPositionᶻCommand& operator=(SetPositionᶻCommand&&) = delete;
    };
}
