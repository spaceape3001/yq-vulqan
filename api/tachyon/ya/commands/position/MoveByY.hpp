////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʸ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʸ, PositionCommand)
    public:
        MoveByʸ(const Header&, double Δy);
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByʸ(const MoveByʸ&, const Header&);
        MoveByʸ(const Header&);
        ~MoveByʸ();
        
    private:
        double  m_Δy = 0.0;

        MoveByʸ(const MoveByʸ&) = delete;
        MoveByʸ(MoveByʸ&&) = delete;
        MoveByʸ& operator=(const MoveByʸ&) = delete;
        MoveByʸ& operator=(MoveByʸ&&) = delete;
    };
}
