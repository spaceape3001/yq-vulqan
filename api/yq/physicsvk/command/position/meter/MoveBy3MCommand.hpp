////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy³MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy³MCommand, PositionCommand)
    public:
        MoveBy³MCommand(const Header&, const Meter3D &Δ);
    
        const Meter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy³MCommand(const MoveBy³MCommand&, const Header&);
        MoveBy³MCommand(const Header&);
        ~MoveBy³MCommand();
        
    private:
        Meter3D  m_Δ = ZERO;
        
        MoveBy³MCommand(const MoveBy³MCommand&) = delete;
        MoveBy³MCommand(MoveBy³MCommand&&) = delete;
        MoveBy³MCommand& operator=(const MoveBy³MCommand&) = delete;
        MoveBy³MCommand& operator=(MoveBy³MCommand&&) = delete;
    };
}
