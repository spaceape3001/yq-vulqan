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
    class MoveBy3MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy3MCommand, PositionCommand)
    public:
        MoveBy3MCommand(const Header&, const Meter3D &Δ);
    
        const Meter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy3MCommand(const MoveBy3MCommand&, const Header&);
        MoveBy3MCommand(const Header&);
        ~MoveBy3MCommand();
        
    private:
        Meter3D  m_Δ = ZERO;
        
        MoveBy3MCommand(const MoveBy3MCommand&) = delete;
        MoveBy3MCommand(MoveBy3MCommand&&) = delete;
        MoveBy3MCommand& operator=(const MoveBy3MCommand&) = delete;
        MoveBy3MCommand& operator=(MoveBy3MCommand&&) = delete;
    };
}
