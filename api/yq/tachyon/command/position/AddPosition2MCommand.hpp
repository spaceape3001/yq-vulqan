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

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition2MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition2MCommand, PositionCommand)
    public:
        AddPosition2MCommand(const Header&, const Meter2D&Δ);
    
        const Meter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition2MCommand(const AddPosition2MCommand&, const Header&);
        AddPosition2MCommand(const Header&);
        ~AddPosition2MCommand();
        
    private:
        Meter2D  m_Δ = ZERO;
        
        AddPosition2MCommand(const AddPosition2MCommand&) = delete;
        AddPosition2MCommand(AddPosition2MCommand&&) = delete;
        AddPosition2MCommand& operator=(const AddPosition2MCommand&) = delete;
        AddPosition2MCommand& operator=(AddPosition2MCommand&&) = delete;
    };
}
