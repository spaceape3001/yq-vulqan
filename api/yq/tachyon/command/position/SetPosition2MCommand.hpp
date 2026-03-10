////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition2MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition2MCommand, PositionCommand)
    public:
        SetPosition2MCommand(const Header&, const Meter2D&);
    
        const Meter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition2MCommand();
        SetPosition2MCommand(const SetPosition2MCommand&, const Header&);
        
    private:
        Meter2D  m_position;
        SetPosition2MCommand(const SetPosition2MCommand&) = delete;
        SetPosition2MCommand(SetPosition2MCommand&&) = delete;
        SetPosition2MCommand& operator=(const SetPosition2MCommand&) = delete;
        SetPosition2MCommand& operator=(SetPosition2MCommand&&) = delete;
    };
}
