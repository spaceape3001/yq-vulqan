////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByᶻ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByᶻ, PositionCommand)
    public:
        MoveByᶻ(const Header&, double Δz);
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByᶻ(const MoveByᶻ&, const Header&);
        MoveByᶻ(const Header&);
        ~MoveByᶻ();
        
    private:
        double  m_Δz = 0.0;
        
        MoveByᶻ(const MoveByᶻ&) = delete;
        MoveByᶻ(MoveByᶻ&&) = delete;
        MoveByᶻ& operator=(const MoveByᶻ&) = delete;
        MoveByᶻ& operator=(MoveByᶻ&&) = delete;
    };
}
