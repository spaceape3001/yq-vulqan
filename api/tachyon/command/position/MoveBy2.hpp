////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy² : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy², PositionCommand)
    public:
        MoveBy²(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy²(const MoveBy²&, const Header&);
        MoveBy²(const Header&);
        ~MoveBy²();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        MoveBy²(const MoveBy²&) = delete;
        MoveBy²(MoveBy²&&) = delete;
        MoveBy²& operator=(const MoveBy²&) = delete;
        MoveBy²& operator=(MoveBy²&&) = delete;
    };
}
