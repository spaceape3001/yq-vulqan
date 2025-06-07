////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class RotateBy³Command : public OrientationCommand {
        YQ_OBJECT_DECLARE(RotateBy³Command, OrientationCommand)
    public:
        RotateBy³Command(const Header&, const Quaternion3D&δ);
        RotateBy³Command(const Header&, const unit::Radian3D&δ);
    
        const Quaternion3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double δw() const { return m_δ.w; }
        double δx() const { return m_δ.x; }
        double δy() const { return m_δ.y; }
        double δz() const { return m_δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        RotateBy³Command(const RotateBy³Command&, const Header&);
        ~RotateBy³Command();
        
    private:
        Quaternion3D const  m_δ;
        
        RotateBy³Command(const RotateBy³Command&) = delete;
        RotateBy³Command(RotateBy³Command&&) = delete;
        RotateBy³Command& operator=(const RotateBy³Command&) = delete;
        RotateBy³Command& operator=(RotateBy³Command&&) = delete;
    };
}
