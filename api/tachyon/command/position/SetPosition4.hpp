////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition⁴ : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition⁴, PositionCommand)
    public:
        SetPosition⁴(const Header&, const Vector4D&);
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition⁴();
        SetPosition⁴(const SetPosition⁴&, const Header&);
    
    private:
        Vector4D  m_position;
        
        SetPosition⁴(const SetPosition⁴&) = delete;
        SetPosition⁴(SetPosition⁴&&) = delete;
        SetPosition⁴& operator=(const SetPosition⁴&) = delete;
        SetPosition⁴& operator=(SetPosition⁴&&) = delete;
    };
}
