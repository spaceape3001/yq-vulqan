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
    class RotateBy3 : public SpatialCommand {
        YQ_OBJECT_DECLARE(RotateBy3, SpatialCommand)
    public:
        RotateBy3(const Header&, const Quaternion3D&δ);
        RotateBy3(const Header&, const unit::Radian3D&δ);
    
        const Quaternion3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double δw() const { return m_δ.w; }
        double δx() const { return m_δ.x; }
        double δy() const { return m_δ.y; }
        double δz() const { return m_δ.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        RotateBy3(const RotateBy3&, const Header&);
        ~RotateBy3();
        
    private:
        Quaternion3D const  m_δ;
        
        RotateBy3(const RotateBy3&) = delete;
        RotateBy3(RotateBy3&&) = delete;
        RotateBy3& operator=(const RotateBy3&) = delete;
        RotateBy3& operator=(RotateBy3&&) = delete;
    };
}
