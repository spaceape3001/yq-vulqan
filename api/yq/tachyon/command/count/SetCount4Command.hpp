////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount⁴Command : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount⁴Command, CountCommand)
    public:
        SetCount⁴Command(const Header&, const Vector4U&);
    
        const Vector4U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        unsigned  z() const { return m_count.z; }
        unsigned  w() const { return m_count.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount⁴Command(const Header&);
        SetCount⁴Command(const SetCount⁴Command&, const Header&);
        ~SetCount⁴Command();

    private:
        Vector4U   m_count = ZERO;
        
        SetCount⁴Command(const SetCount⁴Command&) = delete;
        SetCount⁴Command(SetCount⁴Command&&) = delete;
        SetCount⁴Command& operator=(const SetCount⁴Command&) = delete;
        SetCount⁴Command& operator=(SetCount⁴Command&&) = delete;
    };
}
