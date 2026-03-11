////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy³DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy³DCommand, PositionCommand)
    public:
        MoveBy³DCommand(const Header&, const Vector3D&Δ);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy³DCommand(const MoveBy³DCommand&, const Header&);
        MoveBy³DCommand(const Header&);
        ~MoveBy³DCommand();
        
    private:
        Vector3D  m_Δ = ZERO;
        
        MoveBy³DCommand(const MoveBy³DCommand&) = delete;
        MoveBy³DCommand(MoveBy³DCommand&&) = delete;
        MoveBy³DCommand& operator=(const MoveBy³DCommand&) = delete;
        MoveBy³DCommand& operator=(MoveBy³DCommand&&) = delete;
    };
}
