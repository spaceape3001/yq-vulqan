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
    class SetMaxSize⁴CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize⁴CMCommand, SizeCommand)
    public:
        SetMaxSize⁴CMCommand(const Header&, const Size4CM&);
    
        const Size4CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        Centimeter  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize⁴CMCommand(const Header&);
        SetMaxSize⁴CMCommand(const SetMaxSize⁴CMCommand&, const Header&);
        ~SetMaxSize⁴CMCommand();

    private:
        Size4CM   m_size = ZERO;
        
        SetMaxSize⁴CMCommand(const SetMaxSize⁴CMCommand&) = delete;
        SetMaxSize⁴CMCommand(SetMaxSize⁴CMCommand&&) = delete;
        SetMaxSize⁴CMCommand& operator=(const SetMaxSize⁴CMCommand&) = delete;
        SetMaxSize⁴CMCommand& operator=(SetMaxSize⁴CMCommand&&) = delete;
    };
}
