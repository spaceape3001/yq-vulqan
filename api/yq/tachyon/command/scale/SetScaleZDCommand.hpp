////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetScaleᶻDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleᶻDCommand, ScaleCommand)
    public:
        SetScaleᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleᶻDCommand(const SetScaleᶻDCommand&, const Header&);
        ~SetScaleᶻDCommand();

    private:
        double  m_z;
        
        SetScaleᶻDCommand(const SetScaleᶻDCommand&) = delete;
        SetScaleᶻDCommand(SetScaleᶻDCommand&&) = delete;
        SetScaleᶻDCommand& operator=(const SetScaleᶻDCommand&) = delete;
        SetScaleᶻDCommand& operator=(SetScaleᶻDCommand&&) = delete;
    };
}
