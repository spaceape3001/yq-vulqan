////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale³ : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale³, ScaleCommand)
    public:
        SetScale³(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScale³(const Header&);
        SetScale³(const SetScale³&, const Header&);
        ~SetScale³();

    private:
        Vector3D  m_scale = ZERO;
        
        SetScale³(const SetScale³&) = delete;
        SetScale³(SetScale³&&) = delete;
        SetScale³& operator=(const SetScale³&) = delete;
        SetScale³& operator=(SetScale³&&) = delete;
    };
}
