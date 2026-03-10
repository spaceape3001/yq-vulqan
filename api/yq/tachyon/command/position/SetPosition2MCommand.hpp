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
    class SetPosition²MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition²MCommand, PositionCommand)
    public:
        SetPosition²MCommand(const Header&, const Meter2D&);
    
        const Meter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition²MCommand();
        SetPosition²MCommand(const SetPosition²MCommand&, const Header&);
        
    private:
        Meter2D  m_position;
        SetPosition²MCommand(const SetPosition²MCommand&) = delete;
        SetPosition²MCommand(SetPosition²MCommand&&) = delete;
        SetPosition²MCommand& operator=(const SetPosition²MCommand&) = delete;
        SetPosition²MCommand& operator=(SetPosition²MCommand&&) = delete;
    };
}
