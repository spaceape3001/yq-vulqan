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
    class SetMaxSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize⁴Command, SizeCommand)
    public:
        SetMaxSize⁴Command(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize⁴Command(const Header&);
        SetMaxSize⁴Command(const SetMaxSize⁴Command&, const Header&);
        ~SetMaxSize⁴Command();

    private:
        Size4D   m_size = ZERO;
        
        SetMaxSize⁴Command(const SetMaxSize⁴Command&) = delete;
        SetMaxSize⁴Command(SetMaxSize⁴Command&&) = delete;
        SetMaxSize⁴Command& operator=(const SetMaxSize⁴Command&) = delete;
        SetMaxSize⁴Command& operator=(SetMaxSize⁴Command&&) = delete;
    };
}
