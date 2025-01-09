////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByˣ, SpatialCommand)
    public:
        MoveByˣ(const Header&, double Δx);
    
        static void init_info();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByˣ(const MoveByˣ&, const Header&);
        MoveByˣ(const Header&);
        ~MoveByˣ();

    private:
        double  m_Δx = 0.0;
        
        MoveByˣ(const MoveByˣ&) = delete;
        MoveByˣ(MoveByˣ&&) = delete;
        MoveByˣ& operator=(const MoveByˣ&);
        MoveByˣ& operator=(MoveByˣ&&);
    };
}
