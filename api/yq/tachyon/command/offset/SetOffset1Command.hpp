////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's offset
    class SetOffset¹Command : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffset¹Command, OffsetCommand)
    public:
        SetOffset¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   offset() const  { return m_position; }
        
        static void init_meta();
        
        double  x() const { return m_offset.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetOffset¹Command(const SetOffset¹Command&, const Header&);
        ~SetOffset¹Command();

    private:
        Vector1D const  m_offset;
        
        SetOffset¹Command(const SetOffset¹Command&) = delete;
        SetOffset¹Command(SetOffset¹Command&&) = delete;
        SetOffset¹Command& operator=(const SetOffset¹Command&) = delete;
        SetOffset¹Command& operator=(SetOffset¹Command&&) = delete;
    };
}
