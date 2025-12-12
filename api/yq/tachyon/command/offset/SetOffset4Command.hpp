////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's offset
    class SetOffset⁴Command : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffset⁴Command, OffsetCommand)
    public:
        SetOffset⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   offset() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_offset.x; }
        double  y() const { return m_offset.y; }
        double  z() const { return m_offset.z; }
        double  w() const { return m_offset.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOffset⁴Command();
        SetOffset⁴Command(const SetOffset⁴Command&, const Header&);
    
    private:
        Vector4D  m_offset;
        
        SetOffset⁴Command(const SetOffset⁴Command&) = delete;
        SetOffset⁴Command(SetOffset⁴Command&&) = delete;
        SetOffset⁴Command& operator=(const SetOffset⁴Command&) = delete;
        SetOffset⁴Command& operator=(SetOffset⁴Command&&) = delete;
    };
}
