////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeᶻ, SizeCommand)
    public:
        SetMaxSizeᶻ(const Header&, double);
    
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeᶻ(const Header&);
        SetMaxSizeᶻ(const SetMaxSizeᶻ&, const Header&);
        ~SetMaxSizeᶻ();

    private:
        double   m_z = 0.;
        
        SetMaxSizeᶻ(const SetMaxSizeᶻ&) = delete;
        SetMaxSizeᶻ(SetMaxSizeᶻ&&) = delete;
        SetMaxSizeᶻ& operator=(const SetMaxSizeᶻ&) = delete;
        SetMaxSizeᶻ& operator=(SetMaxSizeᶻ&&) = delete;
    };
}
