////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's offset
    class SetOffset³Command : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffset³Command, OffsetCommand)
    public:
        SetOffset³Command(const Header&, const Vector3D&);
    
        const Vector3D&   offset() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_offset.x; }
        double  y() const { return m_offset.y; }
        double  z() const { return m_offset.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOffset³Command();
        SetOffset³Command(const SetOffset³Command&, const Header&);
    
    private:
        Vector3D  m_offset;
        
        SetOffset³Command(const SetOffset³Command&) = delete;
        SetOffset³Command(SetOffset³Command&&) = delete;
        SetOffset³Command& operator=(const SetOffset³Command&) = delete;
        SetOffset³Command& operator=(SetOffset³Command&&) = delete;
    };
}
