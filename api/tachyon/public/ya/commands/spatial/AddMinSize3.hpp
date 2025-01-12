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
    class AddMinSize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddMinSize³, SpatialCommand)
    public:
        AddMinSize³(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize³(const AddMinSize³&, const Header&);
        AddMinSize³(const Header&);
        ~AddMinSize³();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddMinSize³(const AddMinSize³&) = delete;
        AddMinSize³(AddMinSize³&&) = delete;
        AddMinSize³& operator=(const AddMinSize³&) = delete;
        AddMinSize³& operator=(AddMinSize³&&) = delete;
    };
}
