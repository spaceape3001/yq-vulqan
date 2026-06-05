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
    class AddPosition⁴CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition⁴CMCommand, PositionCommand)
    public:
        AddPosition⁴CMCommand(const Header&, const Centimeter4D&Δ);
    
        const Centimeter4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }
        Centimeter  Δw() const { return m_Δ.w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition⁴CMCommand(const AddPosition⁴CMCommand&, const Header&);
        AddPosition⁴CMCommand(const Header&);
        ~AddPosition⁴CMCommand();
        
    private:
        Centimeter4D  m_Δ = ZERO;
        
        AddPosition⁴CMCommand(const AddPosition⁴CMCommand&) = delete;
        AddPosition⁴CMCommand(AddPosition⁴CMCommand&&) = delete;
        AddPosition⁴CMCommand& operator=(const AddPosition⁴CMCommand&) = delete;
        AddPosition⁴CMCommand& operator=(AddPosition⁴CMCommand&&) = delete;
    };
}
