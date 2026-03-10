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
    class MoveBy2MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy2MCommand, PositionCommand)
    public:
        MoveBy2MCommand(const Header&, const Meter2D&Δ);
    
        const Meter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy2MCommand(const MoveBy2MCommand&, const Header&);
        MoveBy2MCommand(const Header&);
        ~MoveBy2MCommand();
        
    private:
        Meter2D  m_Δ = ZERO;
        
        MoveBy2MCommand(const MoveBy2MCommand&) = delete;
        MoveBy2MCommand(MoveBy2MCommand&&) = delete;
        MoveBy2MCommand& operator=(const MoveBy2MCommand&) = delete;
        MoveBy2MCommand& operator=(MoveBy2MCommand&&) = delete;
    };
}
