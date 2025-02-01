////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMinSizeˣ, SpatialCommand)
    public:
        SetMinSizeˣ(const Header&, double);
    
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeˣ(const Header&);
        SetMinSizeˣ(const SetMinSizeˣ&, const Header&);
        ~SetMinSizeˣ();

    private:
        double   m_x = 0.;
        
        SetMinSizeˣ(const SetMinSizeˣ&) = delete;
        SetMinSizeˣ(SetMinSizeˣ&&) = delete;
        SetMinSizeˣ& operator=(const SetMinSizeˣ&) = delete;
        SetMinSizeˣ& operator=(SetMinSizeˣ&&) = delete;
    };
}
