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
    class SetPosition²Command : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition²Command, PositionCommand)
    public:
        SetPosition²Command(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition²Command();
        SetPosition²Command(const SetPosition²Command&, const Header&);
        
    private:
        Vector2D const  m_position;
        SetPosition²Command(const SetPosition²Command&) = delete;
        SetPosition²Command(SetPosition²Command&&) = delete;
        SetPosition²Command& operator=(const SetPosition²Command&) = delete;
        SetPosition²Command& operator=(SetPosition²Command&&) = delete;
    };
}
