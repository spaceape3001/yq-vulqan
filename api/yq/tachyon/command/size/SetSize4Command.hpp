////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize⁴Command, SizeCommand)
    public:
        SetSize⁴Command(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize⁴Command(const Header&);
        SetSize⁴Command(const SetSize⁴Command&, const Header&);
        ~SetSize⁴Command();

    private:
        Size4D   m_size = ZERO;
        
        SetSize⁴Command(const SetSize⁴Command&) = delete;
        SetSize⁴Command(SetSize⁴Command&&) = delete;
        SetSize⁴Command& operator=(const SetSize⁴Command&) = delete;
        SetSize⁴Command& operator=(SetSize⁴Command&&) = delete;
    };
}
