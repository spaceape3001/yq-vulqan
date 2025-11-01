////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition³Command : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition³Command, PositionCommand)
    public:
        SetPosition³Command(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition³Command();
        SetPosition³Command(const SetPosition³Command&, const Header&);
    
    private:
        Vector3D  m_position;
        
        SetPosition³Command(const SetPosition³Command&) = delete;
        SetPosition³Command(SetPosition³Command&&) = delete;
        SetPosition³Command& operator=(const SetPosition³Command&) = delete;
        SetPosition³Command& operator=(SetPosition³Command&&) = delete;
    };
}
