////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition³DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition³DCommand, PositionCommand)
    public:
        SetPosition³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition³DCommand();
        SetPosition³DCommand(const SetPosition³DCommand&, const Header&);
    
    private:
        Vector3D  m_position;
        
        SetPosition³DCommand(const SetPosition³DCommand&) = delete;
        SetPosition³DCommand(SetPosition³DCommand&&) = delete;
        SetPosition³DCommand& operator=(const SetPosition³DCommand&) = delete;
        SetPosition³DCommand& operator=(SetPosition³DCommand&&) = delete;
    };
}
