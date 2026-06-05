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
    class SetPosition³CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition³CMCommand, PositionCommand)
    public:
        SetPosition³CMCommand(const Header&, const Centimeter3D&);
    
        const Centimeter3D&   position() const  { return m_position; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_position.x; }
        Centimeter  y() const { return m_position.y; }
        Centimeter  z() const { return m_position.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition³CMCommand();
        SetPosition³CMCommand(const SetPosition³CMCommand&, const Header&);
    
    private:
        Centimeter3D  m_position;
        
        SetPosition³CMCommand(const SetPosition³CMCommand&) = delete;
        SetPosition³CMCommand(SetPosition³CMCommand&&) = delete;
        SetPosition³CMCommand& operator=(const SetPosition³CMCommand&) = delete;
        SetPosition³CMCommand& operator=(SetPosition³CMCommand&&) = delete;
    };
}
