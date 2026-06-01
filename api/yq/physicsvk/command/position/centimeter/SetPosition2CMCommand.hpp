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
    class SetPosition²CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition²CMCommand, PositionCommand)
    public:
        SetPosition²CMCommand(const Header&, const Centimeter2D&);
    
        const Centimeter2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition²CMCommand();
        SetPosition²CMCommand(const SetPosition²CMCommand&, const Header&);
        
    private:
        Centimeter2D  m_position = ZERO;
        
        SetPosition²CMCommand(const SetPosition²CMCommand&) = delete;
        SetPosition²CMCommand(SetPosition²CMCommand&&) = delete;
        SetPosition²CMCommand& operator=(const SetPosition²CMCommand&) = delete;
        SetPosition²CMCommand& operator=(SetPosition²CMCommand&&) = delete;
    };
}
