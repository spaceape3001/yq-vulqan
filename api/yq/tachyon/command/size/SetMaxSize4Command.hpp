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
    class SetMaxSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize⁴DCommand, SizeCommand)
    public:
        SetMaxSize⁴DCommand(const Header&, const Size4D&);
    
        const Size4D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        double  w() const { return m_size.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize⁴DCommand(const Header&);
        SetMaxSize⁴DCommand(const SetMaxSize⁴DCommand&, const Header&);
        ~SetMaxSize⁴DCommand();

    private:
        Size4D   m_size = ZERO;
        
        SetMaxSize⁴DCommand(const SetMaxSize⁴DCommand&) = delete;
        SetMaxSize⁴DCommand(SetMaxSize⁴DCommand&&) = delete;
        SetMaxSize⁴DCommand& operator=(const SetMaxSize⁴DCommand&) = delete;
        SetMaxSize⁴DCommand& operator=(SetMaxSize⁴DCommand&&) = delete;
    };
}
