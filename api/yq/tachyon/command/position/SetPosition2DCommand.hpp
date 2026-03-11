////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition²DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition²DCommand, PositionCommand)
    public:
        SetPosition²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition²DCommand();
        SetPosition²DCommand(const SetPosition²DCommand&, const Header&);
        
    private:
        Vector2D   m_position = ZERO;
        
        SetPosition²DCommand(const SetPosition²DCommand&) = delete;
        SetPosition²DCommand(SetPosition²DCommand&&) = delete;
        SetPosition²DCommand& operator=(const SetPosition²DCommand&) = delete;
        SetPosition²DCommand& operator=(SetPosition²DCommand&&) = delete;
    };
}
