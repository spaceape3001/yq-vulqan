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

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition⁴MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition⁴MCommand, PositionCommand)
    public:
        AddPosition⁴MCommand(const Header&, const Meter4D&Δ);
    
        const Meter4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        Meter  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition⁴MCommand(const AddPosition⁴MCommand&, const Header&);
        AddPosition⁴MCommand(const Header&);
        ~AddPosition⁴MCommand();
        
    private:
        Meter4D  m_Δ = ZERO;
        
        AddPosition⁴MCommand(const AddPosition⁴MCommand&) = delete;
        AddPosition⁴MCommand(AddPosition⁴MCommand&&) = delete;
        AddPosition⁴MCommand& operator=(const AddPosition⁴MCommand&) = delete;
        AddPosition⁴MCommand& operator=(AddPosition⁴MCommand&&) = delete;
    };
}
