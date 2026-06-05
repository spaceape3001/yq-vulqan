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
    class SetMinSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize⁴CMCommand, SizeCommand)
    public:
        SetMinSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize⁴CMCommand(const Header&);
        SetMinSize⁴CMCommand(const SetMinSize⁴CMCommand&, const Header&);
        ~SetMinSize⁴CMCommand();

    private:
        Size4CM   m_size = ZERO;
        
        SetMinSize⁴CMCommand(const SetMinSize⁴CMCommand&) = delete;
        SetMinSize⁴CMCommand(SetMinSize⁴CMCommand&&) = delete;
        SetMinSize⁴CMCommand& operator=(const SetMinSize⁴CMCommand&) = delete;
        SetMinSize⁴CMCommand& operator=(SetMinSize⁴CMCommand&&) = delete;
    };
}
