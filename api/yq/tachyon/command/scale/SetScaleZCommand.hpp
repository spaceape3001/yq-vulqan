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
    class SetScaleᶻCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleᶻCommand, ScaleCommand)
    public:
        SetScaleᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleᶻCommand(const SetScaleᶻCommand&, const Header&);
        ~SetScaleᶻCommand();

    private:
        double  m_z;
        
        SetScaleᶻCommand(const SetScaleᶻCommand&) = delete;
        SetScaleᶻCommand(SetScaleᶻCommand&&) = delete;
        SetScaleᶻCommand& operator=(const SetScaleᶻCommand&) = delete;
        SetScaleᶻCommand& operator=(SetScaleᶻCommand&&) = delete;
    };
}
