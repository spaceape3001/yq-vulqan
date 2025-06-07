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
    class SetPosition⁴Command : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPosition⁴Command, PositionCommand)
    public:
        SetPosition⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetPosition⁴Command();
        SetPosition⁴Command(const SetPosition⁴Command&, const Header&);
    
    private:
        Vector4D  m_position;
        
        SetPosition⁴Command(const SetPosition⁴Command&) = delete;
        SetPosition⁴Command(SetPosition⁴Command&&) = delete;
        SetPosition⁴Command& operator=(const SetPosition⁴Command&) = delete;
        SetPosition⁴Command& operator=(SetPosition⁴Command&&) = delete;
    };
}
