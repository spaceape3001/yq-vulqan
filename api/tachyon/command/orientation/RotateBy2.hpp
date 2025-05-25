////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Spinor2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class RotateBy² : public OrientationCommand {
        YQ_OBJECT_DECLARE(RotateBy², OrientationCommand)
    public:
        RotateBy²(const Header&, const Spinor2D&δ);
        RotateBy²(const Header&, Radian δ);
    
        const Spinor2D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double δa() const { return m_δ.a; }
        double δxy() const { return m_δ.xy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        RotateBy²(const RotateBy²&, const Header&);
        ~RotateBy²();
        
    private:
        Spinor2D const  m_δ;
        
        RotateBy²(const RotateBy²&) = delete;
        RotateBy²(RotateBy²&&) = delete;
        RotateBy²& operator=(const RotateBy²&) = delete;
        RotateBy²& operator=(RotateBy²&&) = delete;
    };
}
