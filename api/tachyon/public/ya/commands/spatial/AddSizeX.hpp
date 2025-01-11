////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSizeˣ, SpatialCommand)
    public:
        AddSizeˣ(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣ(const AddSizeˣ&, const Header&);
        AddSizeˣ(const Header&);
        ~AddSizeˣ();

    private:
        double  m_Δx = 0.0;
        
        AddSizeˣ(const AddSizeˣ&) = delete;
        AddSizeˣ(AddSizeˣ&&) = delete;
        AddSizeˣ& operator=(const AddSizeˣ&) = delete;
        AddSizeˣ& operator=(AddSizeˣ&&) = delete;
    };
}
