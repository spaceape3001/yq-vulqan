////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize⁴, SizeCommand)
    public:
        SetMinSize⁴(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize⁴(const Header&);
        SetMinSize⁴(const SetMinSize⁴&, const Header&);
        ~SetMinSize⁴();

    private:
        Size4D   m_size = ZERO;
        
        SetMinSize⁴(const SetMinSize⁴&) = delete;
        SetMinSize⁴(SetMinSize⁴&&) = delete;
        SetMinSize⁴& operator=(const SetMinSize⁴&) = delete;
        SetMinSize⁴& operator=(SetMinSize⁴&&) = delete;
    };
}
