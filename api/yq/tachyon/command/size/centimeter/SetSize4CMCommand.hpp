////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize⁴CMCommand, SizeCommand)
    public:
        SetSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize⁴CMCommand(const Header&);
        SetSize⁴CMCommand(const SetSize⁴CMCommand&, const Header&);
        ~SetSize⁴CMCommand();

    private:
        Size4CM   m_size = ZERO;
        
        SetSize⁴CMCommand(const SetSize⁴CMCommand&) = delete;
        SetSize⁴CMCommand(SetSize⁴CMCommand&&) = delete;
        SetSize⁴CMCommand& operator=(const SetSize⁴CMCommand&) = delete;
        SetSize⁴CMCommand& operator=(SetSize⁴CMCommand&&) = delete;
    };
}
