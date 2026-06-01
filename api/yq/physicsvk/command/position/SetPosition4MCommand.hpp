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
    class SetPosition⁴MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition⁴MCommand, PositionCommand)
    public:
        SetPosition⁴MCommand(const Header&, const Meter4D&);
    
        const Meter4D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        Meter  w() const { return m_position.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition⁴MCommand();
        SetPosition⁴MCommand(const SetPosition⁴MCommand&, const Header&);
    
    private:
        Meter4D  m_position;
        
        SetPosition⁴MCommand(const SetPosition⁴MCommand&) = delete;
        SetPosition⁴MCommand(SetPosition⁴MCommand&&) = delete;
        SetPosition⁴MCommand& operator=(const SetPosition⁴MCommand&) = delete;
        SetPosition⁴MCommand& operator=(SetPosition⁴MCommand&&) = delete;
    };
}
