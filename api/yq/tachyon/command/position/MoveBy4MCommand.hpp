////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy⁴MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy⁴MCommand, PositionCommand)
    public:
        MoveBy⁴MCommand(const Header&, const Meter4D&Δ);
    
        const Meter4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        Meter  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy⁴MCommand(const MoveBy⁴MCommand&, const Header&);
        MoveBy⁴MCommand(const Header&);
        ~MoveBy⁴MCommand();
        
    private:
        Meter4D  m_Δ = ZERO;
        
        MoveBy⁴MCommand(const MoveBy⁴MCommand&) = delete;
        MoveBy⁴MCommand(MoveBy⁴MCommand&&) = delete;
        MoveBy⁴MCommand& operator=(const MoveBy⁴MCommand&) = delete;
        MoveBy⁴MCommand& operator=(MoveBy⁴MCommand&&) = delete;
    };
}
