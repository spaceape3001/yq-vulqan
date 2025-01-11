////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class AddSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSizeˣ, SpatialCommand)
    public:
        AddSizeˣ(const Header&, double);
    
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣ(const Header&);
        AddSizeˣ(const AddSizeˣ&, const Header&);
        ~AddSizeˣ();

    private:
        double   m_x = 0.;
        
        AddSizeˣ(const AddSizeˣ&) = delete;
        AddSizeˣ(AddSizeˣ&&) = delete;
        AddSizeˣ& operator=(const AddSizeˣ&) = delete;
        AddSizeˣ& operator=(AddSizeˣ&&) = delete;
    };
}
