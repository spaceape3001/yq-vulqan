////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddScale³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddScale³, SpatialCommand)
    public:
        AddScale³(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScale³(const AddScale³&, const Header&);
        AddScale³(const Header&);
        ~AddScale³();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddScale³(const AddScale³&) = delete;
        AddScale³(AddScale³&&) = delete;
        AddScale³& operator=(const AddScale³&) = delete;
        AddScale³& operator=(AddScale³&&) = delete;
    };
}
