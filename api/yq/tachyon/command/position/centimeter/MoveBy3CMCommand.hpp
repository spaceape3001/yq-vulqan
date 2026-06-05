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
    class MoveBy³CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy³CMCommand, PositionCommand)
    public:
        MoveBy³CMCommand(const Header&, const Centimeter3D &Δ);
    
        const Centimeter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy³CMCommand(const MoveBy³CMCommand&, const Header&);
        MoveBy³CMCommand(const Header&);
        ~MoveBy³CMCommand();
        
    private:
        Centimeter3D  m_Δ = ZERO;
        
        MoveBy³CMCommand(const MoveBy³CMCommand&) = delete;
        MoveBy³CMCommand(MoveBy³CMCommand&&) = delete;
        MoveBy³CMCommand& operator=(const MoveBy³CMCommand&) = delete;
        MoveBy³CMCommand& operator=(MoveBy³CMCommand&&) = delete;
    };
}
