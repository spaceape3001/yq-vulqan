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
    class SetMaxSize⁴MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize⁴MCommand, SizeCommand)
    public:
        SetMaxSize⁴MCommand(const Header&, const Size4M&);
    
        const Size4M&   size() const  { return m_size; }
        
        static void init_meta();
        
        Meter  x() const { return m_size.x; }
        Meter  y() const { return m_size.y; }
        Meter  z() const { return m_size.z; }
        Meter  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize⁴MCommand(const Header&);
        SetMaxSize⁴MCommand(const SetMaxSize⁴MCommand&, const Header&);
        ~SetMaxSize⁴MCommand();

    private:
        Size4M   m_size = ZERO;
        
        SetMaxSize⁴MCommand(const SetMaxSize⁴MCommand&) = delete;
        SetMaxSize⁴MCommand(SetMaxSize⁴MCommand&&) = delete;
        SetMaxSize⁴MCommand& operator=(const SetMaxSize⁴MCommand&) = delete;
        SetMaxSize⁴MCommand& operator=(SetMaxSize⁴MCommand&&) = delete;
    };
}
