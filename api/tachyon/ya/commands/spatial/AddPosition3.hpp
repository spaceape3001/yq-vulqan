////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddPosition³, SpatialCommand)
    public:
        AddPosition³(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition³(const AddPosition³&, const Header&);
        AddPosition³(const Header&);
        ~AddPosition³();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        AddPosition³(const AddPosition³&) = delete;
        AddPosition³(AddPosition³&&) = delete;
        AddPosition³& operator=(const AddPosition³&) = delete;
        AddPosition³& operator=(AddPosition³&&) = delete;
    };
}
