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
    class SetPositionᶻDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻDCommand, PositionCommand)
    public:
        SetPositionᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionᶻDCommand(const SetPositionᶻDCommand&, const Header&);
        ~SetPositionᶻDCommand();
        
    private:
        double  m_z = 0.0;
        
        SetPositionᶻDCommand(const SetPositionᶻDCommand&) = delete;
        SetPositionᶻDCommand(SetPositionᶻDCommand&&) = delete;
        SetPositionᶻDCommand& operator=(const SetPositionᶻDCommand&) = delete;
        SetPositionᶻDCommand& operator=(SetPositionᶻDCommand&&) = delete;
    };
}
