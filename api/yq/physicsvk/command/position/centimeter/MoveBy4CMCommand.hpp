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
    class MoveBy⁴CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy⁴CMCommand, PositionCommand)
    public:
        MoveBy⁴CMCommand(const Header&, const Centimeter4D&Δ);
    
        const Centimeter4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        Centimeter  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy⁴CMCommand(const MoveBy⁴CMCommand&, const Header&);
        MoveBy⁴CMCommand(const Header&);
        ~MoveBy⁴CMCommand();
        
    private:
        Centimeter4D  m_Δ = ZERO;
        
        MoveBy⁴CMCommand(const MoveBy⁴CMCommand&) = delete;
        MoveBy⁴CMCommand(MoveBy⁴CMCommand&&) = delete;
        MoveBy⁴CMCommand& operator=(const MoveBy⁴CMCommand&) = delete;
        MoveBy⁴CMCommand& operator=(MoveBy⁴CMCommand&&) = delete;
    };
}
