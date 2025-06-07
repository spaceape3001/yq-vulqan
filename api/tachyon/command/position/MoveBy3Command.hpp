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
    class MoveBy³Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy³Command, PositionCommand)
    public:
        MoveBy³Command(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy³Command(const MoveBy³Command&, const Header&);
        MoveBy³Command(const Header&);
        ~MoveBy³Command();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        MoveBy³Command(const MoveBy³Command&) = delete;
        MoveBy³Command(MoveBy³Command&&) = delete;
        MoveBy³Command& operator=(const MoveBy³Command&) = delete;
        MoveBy³Command& operator=(MoveBy³Command&&) = delete;
    };
}
