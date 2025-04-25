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
    class SetMaxSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize⁴, SizeCommand)
    public:
        SetMaxSize⁴(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize⁴(const Header&);
        SetMaxSize⁴(const SetMaxSize⁴&, const Header&);
        ~SetMaxSize⁴();

    private:
        Size4D   m_size = ZERO;
        
        SetMaxSize⁴(const SetMaxSize⁴&) = delete;
        SetMaxSize⁴(SetMaxSize⁴&&) = delete;
        SetMaxSize⁴& operator=(const SetMaxSize⁴&) = delete;
        SetMaxSize⁴& operator=(SetMaxSize⁴&&) = delete;
    };
}
