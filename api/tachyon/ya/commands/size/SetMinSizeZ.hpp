////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeᶻ, SizeCommand)
    public:
        SetMinSizeᶻ(const Header&, double);
    
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeᶻ(const Header&);
        SetMinSizeᶻ(const SetMinSizeᶻ&, const Header&);
        ~SetMinSizeᶻ();

    private:
        double   m_z = 0.;
        
        SetMinSizeᶻ(const SetMinSizeᶻ&) = delete;
        SetMinSizeᶻ(SetMinSizeᶻ&&) = delete;
        SetMinSizeᶻ& operator=(const SetMinSizeᶻ&) = delete;
        SetMinSizeᶻ& operator=(SetMinSizeᶻ&&) = delete;
    };
}
