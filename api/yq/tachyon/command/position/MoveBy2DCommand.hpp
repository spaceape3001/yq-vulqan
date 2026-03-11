////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy²DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy²DCommand, PositionCommand)
    public:
        MoveBy²DCommand(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy²DCommand(const MoveBy²DCommand&, const Header&);
        MoveBy²DCommand(const Header&);
        ~MoveBy²DCommand();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        MoveBy²DCommand(const MoveBy²DCommand&) = delete;
        MoveBy²DCommand(MoveBy²DCommand&&) = delete;
        MoveBy²DCommand& operator=(const MoveBy²DCommand&) = delete;
        MoveBy²DCommand& operator=(MoveBy²DCommand&&) = delete;
    };
}
