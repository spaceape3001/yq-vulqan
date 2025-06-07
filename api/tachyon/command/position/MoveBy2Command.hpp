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
    class MoveBy²Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy²Command, PositionCommand)
    public:
        MoveBy²Command(const Header&, const Vector2D&Δ);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveBy²Command(const MoveBy²Command&, const Header&);
        MoveBy²Command(const Header&);
        ~MoveBy²Command();
        
    private:
        Vector2D  m_Δ = ZERO;
        
        MoveBy²Command(const MoveBy²Command&) = delete;
        MoveBy²Command(MoveBy²Command&&) = delete;
        MoveBy²Command& operator=(const MoveBy²Command&) = delete;
        MoveBy²Command& operator=(MoveBy²Command&&) = delete;
    };
}
