////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetSizeᶻ, SpatialCommand)
    public:
        SetSizeᶻ(const Header&, double);
    
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeᶻ(const Header&);
        SetSizeᶻ(const SetSizeᶻ&, const Header&);
        ~SetSizeᶻ();

    private:
        double   m_z = 0.;
        
        SetSizeᶻ(const SetSizeᶻ&) = delete;
        SetSizeᶻ(SetSizeᶻ&&) = delete;
        SetSizeᶻ& operator=(const SetSizeᶻ&) = delete;
        SetSizeᶻ& operator=(SetSizeᶻ&&) = delete;
    };
}
