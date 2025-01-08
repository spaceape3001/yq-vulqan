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
    class MultiplyScaleᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleᶻ, SpatialCommand)
    public:
        MultiplyScaleᶻ(const Header&, double);
        
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleᶻ(const MultiplyScaleᶻ&, const Header&);
        ~MultiplyScaleᶻ();

    private:
        double const  m_z;
        
        MultiplyScaleᶻ(const MultiplyScaleᶻ&) = delete;
        MultiplyScaleᶻ(MultiplyScaleᶻ&&) = delete;
        MultiplyScaleᶻ& operator=(const MultiplyScaleᶻ&) = delete;
        MultiplyScaleᶻ& operator=(MultiplyScaleᶻ&&) = delete;
    };
}
