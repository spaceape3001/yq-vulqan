////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize⁴, SizeCommand)
    public:
        SetSize⁴(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize⁴(const Header&);
        SetSize⁴(const SetSize⁴&, const Header&);
        ~SetSize⁴();

    private:
        Size4D   m_size = ZERO;
        
        SetSize⁴(const SetSize⁴&) = delete;
        SetSize⁴(SetSize⁴&&) = delete;
        SetSize⁴& operator=(const SetSize⁴&) = delete;
        SetSize⁴& operator=(SetSize⁴&&) = delete;
    };
}
