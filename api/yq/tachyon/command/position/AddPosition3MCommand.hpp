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
    class AddPosition³MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition³MCommand, PositionCommand)
    public:
        AddPosition³MCommand(const Header&, const Meter3D&Δ);
    
        const Meter3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition³MCommand(const AddPosition³MCommand&, const Header&);
        AddPosition³MCommand(const Header&);
        ~AddPosition³MCommand();
        
    private:
        Meter3D  m_Δ = ZERO;
        
        AddPosition³MCommand(const AddPosition³MCommand&) = delete;
        AddPosition³MCommand(AddPosition³MCommand&&) = delete;
        AddPosition³MCommand& operator=(const AddPosition³MCommand&) = delete;
        AddPosition³MCommand& operator=(AddPosition³MCommand&&) = delete;
    };
}
