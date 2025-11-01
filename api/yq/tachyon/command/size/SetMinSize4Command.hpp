////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize⁴Command, SizeCommand)
    public:
        SetMinSize⁴Command(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize⁴Command(const Header&);
        SetMinSize⁴Command(const SetMinSize⁴Command&, const Header&);
        ~SetMinSize⁴Command();

    private:
        Size4D   m_size = ZERO;
        
        SetMinSize⁴Command(const SetMinSize⁴Command&) = delete;
        SetMinSize⁴Command(SetMinSize⁴Command&&) = delete;
        SetMinSize⁴Command& operator=(const SetMinSize⁴Command&) = delete;
        SetMinSize⁴Command& operator=(SetMinSize⁴Command&&) = delete;
    };
}
