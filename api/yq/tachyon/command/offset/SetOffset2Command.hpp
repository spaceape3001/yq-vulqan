////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's offset
    class SetOffset²Command : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffset²Command, OffsetCommand)
    public:
        SetOffset²Command(const Header&, const Vector2D&);
    
        const Vector2D&   offset() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_offset.x; }
        double  y() const { return m_offset.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOffset²Command();
        SetOffset²Command(const SetOffset²Command&, const Header&);
        
    private:
        Vector2D const  m_offset;
        SetOffset²Command(const SetOffset²Command&) = delete;
        SetOffset²Command(SetOffset²Command&&) = delete;
        SetOffset²Command& operator=(const SetOffset²Command&) = delete;
        SetOffset²Command& operator=(SetOffset²Command&&) = delete;
    };
}
