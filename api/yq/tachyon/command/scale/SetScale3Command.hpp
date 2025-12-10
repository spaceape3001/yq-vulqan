////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale³Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale³Command, ScaleCommand)
    public:
        SetScale³Command(const Header&, const Vector3D&);
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScale³Command(const Header&);
        SetScale³Command(const SetScale³Command&, const Header&);
        ~SetScale³Command();

    private:
        Vector3D  m_scale = ZERO;
        
        SetScale³Command(const SetScale³Command&) = delete;
        SetScale³Command(SetScale³Command&&) = delete;
        SetScale³Command& operator=(const SetScale³Command&) = delete;
        SetScale³Command& operator=(SetScale³Command&&) = delete;
    };
}
