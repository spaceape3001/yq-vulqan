////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy³ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy³, PositionCommand)
    public:
        MoveBy³(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy³(const MoveBy³&, const Header&);
        MoveBy³(const Header&);
        ~MoveBy³();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        MoveBy³(const MoveBy³&) = delete;
        MoveBy³(MoveBy³&&) = delete;
        MoveBy³& operator=(const MoveBy³&) = delete;
        MoveBy³& operator=(MoveBy³&&) = delete;
    };
}
