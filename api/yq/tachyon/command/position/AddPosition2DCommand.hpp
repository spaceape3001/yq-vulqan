////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition²DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition²DCommand, PositionCommand)
    public:
        AddPosition²DCommand(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPosition²DCommand(const AddPosition²DCommand&, const Header&);
        AddPosition²DCommand(const Header&);
        ~AddPosition²DCommand();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        AddPosition²DCommand(const AddPosition²DCommand&) = delete;
        AddPosition²DCommand(AddPosition²DCommand&&) = delete;
        AddPosition²DCommand& operator=(const AddPosition²DCommand&) = delete;
        AddPosition²DCommand& operator=(AddPosition²DCommand&&) = delete;
    };
}
