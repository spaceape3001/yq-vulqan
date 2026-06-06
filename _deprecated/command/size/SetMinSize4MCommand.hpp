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
    class SetMinSize⁴MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize⁴MCommand, SizeCommand)
    public:
        SetMinSize⁴MCommand(const Header&, const Size4M&);
    
        const Size4M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        Meter  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize⁴MCommand(const Header&);
        SetMinSize⁴MCommand(const SetMinSize⁴MCommand&, const Header&);
        ~SetMinSize⁴MCommand();

    private:
        Size4M   m_size = ZERO;
        
        SetMinSize⁴MCommand(const SetMinSize⁴MCommand&) = delete;
        SetMinSize⁴MCommand(SetMinSize⁴MCommand&&) = delete;
        SetMinSize⁴MCommand& operator=(const SetMinSize⁴MCommand&) = delete;
        SetMinSize⁴MCommand& operator=(SetMinSize⁴MCommand&&) = delete;
    };
}
