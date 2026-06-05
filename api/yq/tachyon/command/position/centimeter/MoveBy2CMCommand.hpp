////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy²CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy²CMCommand, PositionCommand)
    public:
        MoveBy²CMCommand(const Header&, const Centimeter2D&Δ);
    
        const Centimeter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy²CMCommand(const MoveBy²CMCommand&, const Header&);
        MoveBy²CMCommand(const Header&);
        ~MoveBy²CMCommand();
        
    private:
        Centimeter2D  m_Δ = ZERO;
        
        MoveBy²CMCommand(const MoveBy²CMCommand&) = delete;
        MoveBy²CMCommand(MoveBy²CMCommand&&) = delete;
        MoveBy²CMCommand& operator=(const MoveBy²CMCommand&) = delete;
        MoveBy²CMCommand& operator=(MoveBy²CMCommand&&) = delete;
    };
}
