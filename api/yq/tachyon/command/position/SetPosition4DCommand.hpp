////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition⁴DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition⁴DCommand, PositionCommand)
    public:
        SetPosition⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition⁴DCommand();
        SetPosition⁴DCommand(const SetPosition⁴DCommand&, const Header&);
    
    private:
        Vector4D  m_position;
        
        SetPosition⁴DCommand(const SetPosition⁴DCommand&) = delete;
        SetPosition⁴DCommand(SetPosition⁴DCommand&&) = delete;
        SetPosition⁴DCommand& operator=(const SetPosition⁴DCommand&) = delete;
        SetPosition⁴DCommand& operator=(SetPosition⁴DCommand&&) = delete;
    };
}
