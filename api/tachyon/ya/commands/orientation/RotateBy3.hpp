////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class RotateBy³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(RotateBy³, SpatialCommand)
    public:
        RotateBy³(const Header&, const Quaternion3D&δ);
        RotateBy³(const Header&, const unit::Radian3D&δ);
    
        const Quaternion3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double δw() const { return m_δ.w; }
        double δx() const { return m_δ.x; }
        double δy() const { return m_δ.y; }
        double δz() const { return m_δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        RotateBy³(const RotateBy³&, const Header&);
        ~RotateBy³();
        
    private:
        Quaternion3D const  m_δ;
        
        RotateBy³(const RotateBy³&) = delete;
        RotateBy³(RotateBy³&&) = delete;
        RotateBy³& operator=(const RotateBy³&) = delete;
        RotateBy³& operator=(RotateBy³&&) = delete;
    };
}
