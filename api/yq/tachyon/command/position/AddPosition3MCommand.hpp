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
    class AddPosition3MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition3MCommand, PositionCommand)
    public:
        AddPosition3MCommand(const Header&, const Meter3D&Δ);
    
        const Meter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition3MCommand(const AddPosition3MCommand&, const Header&);
        AddPosition3MCommand(const Header&);
        ~AddPosition3MCommand();
        
    private:
        Meter3D  m_Δ = ZERO;
        
        AddPosition3MCommand(const AddPosition3MCommand&) = delete;
        AddPosition3MCommand(AddPosition3MCommand&&) = delete;
        AddPosition3MCommand& operator=(const AddPosition3MCommand&) = delete;
        AddPosition3MCommand& operator=(AddPosition3MCommand&&) = delete;
    };
}
