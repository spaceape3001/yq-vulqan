////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class AddSizeᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻ, SpatialCommand)
    public:
        AddSizeᶻ(const Header&, double);
    
        static void init_info();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻ(const Header&);
        AddSizeᶻ(const AddSizeᶻ&, const Header&);
        ~AddSizeᶻ();

    private:
        double   m_z = 0.;
        
        AddSizeᶻ(const AddSizeᶻ&) = delete;
        AddSizeᶻ(AddSizeᶻ&&) = delete;
        AddSizeᶻ& operator=(const AddSizeᶻ&) = delete;
        AddSizeᶻ& operator=(AddSizeᶻ&&) = delete;
    };
}
