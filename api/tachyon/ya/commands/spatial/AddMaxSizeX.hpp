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
    class AddMaxSizeˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeˣ, SpatialCommand)
    public:
        AddMaxSizeˣ(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeˣ(const AddMaxSizeˣ&, const Header&);
        AddMaxSizeˣ(const Header&);
        ~AddMaxSizeˣ();

    private:
        double  m_Δx = 0.0;
        
        AddMaxSizeˣ(const AddMaxSizeˣ&) = delete;
        AddMaxSizeˣ(AddMaxSizeˣ&&) = delete;
        AddMaxSizeˣ& operator=(const AddMaxSizeˣ&) = delete;
        AddMaxSizeˣ& operator=(AddMaxSizeˣ&&) = delete;
    };
}
