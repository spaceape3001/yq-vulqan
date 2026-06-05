////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition⁴CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition⁴CMCommand, PositionCommand)
    public:
        SetPosition⁴CMCommand(const Header&, const Centimeter4D&);
    
        const Centimeter4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }
        Centimeter  w() const { return m_position.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition⁴CMCommand();
        SetPosition⁴CMCommand(const SetPosition⁴CMCommand&, const Header&);
    
    private:
        Centimeter4D  m_position;
        
        SetPosition⁴CMCommand(const SetPosition⁴CMCommand&) = delete;
        SetPosition⁴CMCommand(SetPosition⁴CMCommand&&) = delete;
        SetPosition⁴CMCommand& operator=(const SetPosition⁴CMCommand&) = delete;
        SetPosition⁴CMCommand& operator=(SetPosition⁴CMCommand&&) = delete;
    };
}
