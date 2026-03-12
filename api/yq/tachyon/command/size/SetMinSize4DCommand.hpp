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
    class SetMinSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize⁴DCommand, SizeCommand)
    public:
        SetMinSize⁴DCommand(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize⁴DCommand(const Header&);
        SetMinSize⁴DCommand(const SetMinSize⁴DCommand&, const Header&);
        ~SetMinSize⁴DCommand();

    private:
        Size4D   m_size = ZERO;
        
        SetMinSize⁴DCommand(const SetMinSize⁴DCommand&) = delete;
        SetMinSize⁴DCommand(SetMinSize⁴DCommand&&) = delete;
        SetMinSize⁴DCommand& operator=(const SetMinSize⁴DCommand&) = delete;
        SetMinSize⁴DCommand& operator=(SetMinSize⁴DCommand&&) = delete;
    };
}
