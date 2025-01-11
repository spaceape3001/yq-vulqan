////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetSizeˣ, SpatialCommand)
    public:
        SetSizeˣ(const Header&, double);
    
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeˣ(const Header&);
        SetSizeˣ(const SetSizeˣ&, const Header&);
        ~SetSizeˣ();

    private:
        double   m_x = 0.;
        
        SetSizeˣ(const SetSizeˣ&) = delete;
        SetSizeˣ(SetSizeˣ&&) = delete;
        SetSizeˣ& operator=(const SetSizeˣ&) = delete;
        SetSizeˣ& operator=(SetSizeˣ&&) = delete;
    };
}
