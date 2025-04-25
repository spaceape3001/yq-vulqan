////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʷ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʷ, PositionCommand)
    public:
        MoveByʷ(const Header&, double Δw);
    
        static void init_info();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByʷ(const MoveByʷ&, const Header&);
        MoveByʷ(const Header&);
        ~MoveByʷ();

    private:
        double  m_Δw = 0.0;
        
        MoveByʷ(const MoveByʷ&) = delete;
        MoveByʷ(MoveByʷ&&) = delete;
        MoveByʷ& operator=(const MoveByʷ&);
        MoveByʷ& operator=(MoveByʷ&&);
    };
}
