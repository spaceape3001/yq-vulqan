////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyScaleʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleʸ, SpatialCommand)
    public:
        MultiplyScaleʸ(const Header&, double);
        
        static void init_info();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleʸ(const MultiplyScaleʸ&, const Header&);
        MultiplyScaleʸ(const Header&);
        ~MultiplyScaleʸ();

    private:
        double  m_δy = 0.0;
        
        MultiplyScaleʸ(const MultiplyScaleʸ&) = delete;
        MultiplyScaleʸ(MultiplyScaleʸ&&) = delete;
        MultiplyScaleʸ& operator=(const MultiplyScaleʸ&) = delete;
        MultiplyScaleʸ& operator=(MultiplyScaleʸ&&) = delete;
    };
}
