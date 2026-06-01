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
    class MoveBy²MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy²MCommand, PositionCommand)
    public:
        MoveBy²MCommand(const Header&, const Meter2D&Δ);
    
        const Meter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy²MCommand(const MoveBy²MCommand&, const Header&);
        MoveBy²MCommand(const Header&);
        ~MoveBy²MCommand();
        
    private:
        Meter2D  m_Δ = ZERO;
        
        MoveBy²MCommand(const MoveBy²MCommand&) = delete;
        MoveBy²MCommand(MoveBy²MCommand&&) = delete;
        MoveBy²MCommand& operator=(const MoveBy²MCommand&) = delete;
        MoveBy²MCommand& operator=(MoveBy²MCommand&&) = delete;
    };
}
