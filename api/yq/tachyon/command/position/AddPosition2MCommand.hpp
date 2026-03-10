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
    class AddPosition²MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition²MCommand, PositionCommand)
    public:
        AddPosition²MCommand(const Header&, const Meter2D&Δ);
    
        const Meter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition²MCommand(const AddPosition²MCommand&, const Header&);
        AddPosition²MCommand(const Header&);
        ~AddPosition²MCommand();
        
    private:
        Meter2D  m_Δ = ZERO;
        
        AddPosition²MCommand(const AddPosition²MCommand&) = delete;
        AddPosition²MCommand(AddPosition²MCommand&&) = delete;
        AddPosition²MCommand& operator=(const AddPosition²MCommand&) = delete;
        AddPosition²MCommand& operator=(AddPosition²MCommand&&) = delete;
    };
}
