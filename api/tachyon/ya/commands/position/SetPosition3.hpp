////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition³ : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition³, PositionCommand)
    public:
        SetPosition³(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition³();
        SetPosition³(const SetPosition³&, const Header&);
    
    private:
        Vector3D  m_position;
        
        SetPosition³(const SetPosition³&) = delete;
        SetPosition³(SetPosition³&&) = delete;
        SetPosition³& operator=(const SetPosition³&) = delete;
        SetPosition³& operator=(SetPosition³&&) = delete;
    };
}
