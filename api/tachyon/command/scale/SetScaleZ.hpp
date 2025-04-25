////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetScaleᶻ : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleᶻ, ScaleCommand)
    public:
        SetScaleᶻ(const Header&, double);
        
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleᶻ(const SetScaleᶻ&, const Header&);
        ~SetScaleᶻ();

    private:
        double  m_z;
        
        SetScaleᶻ(const SetScaleᶻ&) = delete;
        SetScaleᶻ(SetScaleᶻ&&) = delete;
        SetScaleᶻ& operator=(const SetScaleᶻ&) = delete;
        SetScaleᶻ& operator=(SetScaleᶻ&&) = delete;
    };
}
