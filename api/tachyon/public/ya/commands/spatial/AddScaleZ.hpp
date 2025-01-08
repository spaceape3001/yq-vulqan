////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddScaleᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScaleᶻ, SpatialCommand)
    public:
        AddScaleᶻ(const Header&, double);
        
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleᶻ(const AddScaleᶻ&, const Header&);
        ~AddScaleᶻ();

    private:
        double const  m_z;
        
        AddScaleᶻ(const AddScaleᶻ&) = delete;
        AddScaleᶻ(AddScaleᶻ&&) = delete;
        AddScaleᶻ& operator=(const AddScaleᶻ&) = delete;
        AddScaleᶻ& operator=(AddScaleᶻ&&) = delete;
    };
}
