////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition² : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition², PositionCommand)
    public:
        SetPosition²(const Header&, const Vector2D&);
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition²();
        SetPosition²(const SetPosition²&, const Header&);
        
    private:
        Vector2D const  m_position;
        SetPosition²(const SetPosition²&) = delete;
        SetPosition²(SetPosition²&&) = delete;
        SetPosition²& operator=(const SetPosition²&) = delete;
        SetPosition²& operator=(SetPosition²&&) = delete;
    };
}
