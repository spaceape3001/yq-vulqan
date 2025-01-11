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
    class AddSize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSize³, SpatialCommand)
    public:
        AddSize³(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³(const AddSize³&, const Header&);
        AddSize³(const Header&);
        ~AddSize³();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddSize³(const AddSize³&) = delete;
        AddSize³(AddSize³&&) = delete;
        AddSize³& operator=(const AddSize³&) = delete;
        AddSize³& operator=(AddSize³&&) = delete;
    };
}
