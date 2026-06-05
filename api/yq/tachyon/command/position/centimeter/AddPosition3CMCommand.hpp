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

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition³CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition³CMCommand, PositionCommand)
    public:
        AddPosition³CMCommand(const Header&, const Centimeter3D&Δ);
    
        const Centimeter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }
        Centimeter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition³CMCommand(const AddPosition³CMCommand&, const Header&);
        AddPosition³CMCommand(const Header&);
        ~AddPosition³CMCommand();
        
    private:
        Centimeter3D  m_Δ = ZERO;
        
        AddPosition³CMCommand(const AddPosition³CMCommand&) = delete;
        AddPosition³CMCommand(AddPosition³CMCommand&&) = delete;
        AddPosition³CMCommand& operator=(const AddPosition³CMCommand&) = delete;
        AddPosition³CMCommand& operator=(AddPosition³CMCommand&&) = delete;
    };
}
