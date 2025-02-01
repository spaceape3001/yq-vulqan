////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeˣ, SpatialCommand)
    public:
        SetMaxSizeˣ(const Header&, double);
    
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeˣ(const Header&);
        SetMaxSizeˣ(const SetMaxSizeˣ&, const Header&);
        ~SetMaxSizeˣ();

    private:
        double   m_x = 0.;
        
        SetMaxSizeˣ(const SetMaxSizeˣ&) = delete;
        SetMaxSizeˣ(SetMaxSizeˣ&&) = delete;
        SetMaxSizeˣ& operator=(const SetMaxSizeˣ&) = delete;
        SetMaxSizeˣ& operator=(SetMaxSizeˣ&&) = delete;
    };
}
