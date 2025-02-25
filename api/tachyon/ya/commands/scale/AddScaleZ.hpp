////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddScaleᶻ : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleᶻ, ScaleCommand)
    public:
        AddScaleᶻ(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleᶻ(const AddScaleᶻ&, const Header&);
        AddScaleᶻ(const Header&);
        ~AddScaleᶻ();

    private:
        double  m_Δz = 0.0;
        
        AddScaleᶻ(const AddScaleᶻ&) = delete;
        AddScaleᶻ(AddScaleᶻ&&) = delete;
        AddScaleᶻ& operator=(const AddScaleᶻ&) = delete;
        AddScaleᶻ& operator=(AddScaleᶻ&&) = delete;
    };
}
