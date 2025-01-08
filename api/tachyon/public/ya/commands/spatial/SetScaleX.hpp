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
    class SetScaleˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleˣ, SpatialCommand)
    public:
        SetScaleˣ(const Header&, double);
        
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleˣ(const SetScaleˣ&, const Header&);
        ~SetScaleˣ();

    private:
        double const  m_x;
        
        SetScaleˣ(const SetScaleˣ&) = delete;
        SetScaleˣ(SetScaleˣ&&) = delete;
        SetScaleˣ& operator=(const SetScaleˣ&) = delete;
        SetScaleˣ& operator=(SetScaleˣ&&) = delete;
    };
}
