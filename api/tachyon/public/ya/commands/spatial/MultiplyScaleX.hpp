////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyScaleˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleˣ, SpatialCommand)
    public:
        MultiplyScaleˣ(const Header&, double);
        
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleˣ(const MultiplyScaleˣ&, const Header&);
        ~MultiplyScaleˣ();

    private:
        double const  m_x;
        
        MultiplyScaleˣ(const MultiplyScaleˣ&) = delete;
        MultiplyScaleˣ(MultiplyScaleˣ&&) = delete;
        MultiplyScaleˣ& operator=(const MultiplyScaleˣ&) = delete;
        MultiplyScaleˣ& operator=(MultiplyScaleˣ&&) = delete;
    };
}
