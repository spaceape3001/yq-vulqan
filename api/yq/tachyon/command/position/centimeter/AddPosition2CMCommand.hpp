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
    class AddPosition²CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition²CMCommand, PositionCommand)
    public:
        AddPosition²CMCommand(const Header&, const Centimeter2D&Δ);
    
        const Centimeter2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }
        Centimeter  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition²CMCommand(const AddPosition²CMCommand&, const Header&);
        AddPosition²CMCommand(const Header&);
        ~AddPosition²CMCommand();
        
    private:
        Centimeter2D  m_Δ = ZERO;
        
        AddPosition²CMCommand(const AddPosition²CMCommand&) = delete;
        AddPosition²CMCommand(AddPosition²CMCommand&&) = delete;
        AddPosition²CMCommand& operator=(const AddPosition²CMCommand&) = delete;
        AddPosition²CMCommand& operator=(AddPosition²CMCommand&&) = delete;
    };
}
