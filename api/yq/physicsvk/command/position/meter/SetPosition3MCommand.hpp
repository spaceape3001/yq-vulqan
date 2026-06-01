////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition³MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition³MCommand, PositionCommand)
    public:
        SetPosition³MCommand(const Header&, const Meter3D&);
    
        const Meter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition³MCommand();
        SetPosition³MCommand(const SetPosition³MCommand&, const Header&);
    
    private:
        Meter3D  m_position;
        
        SetPosition³MCommand(const SetPosition³MCommand&) = delete;
        SetPosition³MCommand(SetPosition³MCommand&&) = delete;
        SetPosition³MCommand& operator=(const SetPosition³MCommand&) = delete;
        SetPosition³MCommand& operator=(SetPosition³MCommand&&) = delete;
    };
}
