////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize²DCommand, SizeCommand)
    public:
        SetSize²DCommand(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize²DCommand(const Header&);
        SetSize²DCommand(const SetSize²DCommand&, const Header&);
        ~SetSize²DCommand();

    private:
        Size2D   m_size = ZERO;
        
        SetSize²DCommand(const SetSize²DCommand&) = delete;
        SetSize²DCommand(SetSize²DCommand&&) = delete;
        SetSize²DCommand& operator=(const SetSize²DCommand&) = delete;
        SetSize²DCommand& operator=(SetSize²DCommand&&) = delete;
    };
}
