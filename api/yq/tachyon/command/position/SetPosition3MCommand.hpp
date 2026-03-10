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
    class SetPosition3MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition3MCommand, PositionCommand)
    public:
        SetPosition3MCommand(const Header&, const Meter3D&);
    
        const Meter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition3MCommand();
        SetPosition3MCommand(const SetPosition3MCommand&, const Header&);
    
    private:
        Meter3D  m_position;
        
        SetPosition3MCommand(const SetPosition3MCommand&) = delete;
        SetPosition3MCommand(SetPosition3MCommand&&) = delete;
        SetPosition3MCommand& operator=(const SetPosition3MCommand&) = delete;
        SetPosition3MCommand& operator=(SetPosition3MCommand&&) = delete;
    };
}
