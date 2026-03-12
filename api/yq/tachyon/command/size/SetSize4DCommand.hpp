////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize⁴DCommand, SizeCommand)
    public:
        SetSize⁴DCommand(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize⁴DCommand(const Header&);
        SetSize⁴DCommand(const SetSize⁴DCommand&, const Header&);
        ~SetSize⁴DCommand();

    private:
        Size4D   m_size = ZERO;
        
        SetSize⁴DCommand(const SetSize⁴DCommand&) = delete;
        SetSize⁴DCommand(SetSize⁴DCommand&&) = delete;
        SetSize⁴DCommand& operator=(const SetSize⁴DCommand&) = delete;
        SetSize⁴DCommand& operator=(SetSize⁴DCommand&&) = delete;
    };
}
