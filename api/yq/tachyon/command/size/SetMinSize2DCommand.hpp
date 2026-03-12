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
    class SetMinSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize²DCommand, SizeCommand)
    public:
        SetMinSize²DCommand(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize²DCommand(const Header&);
        SetMinSize²DCommand(const SetMinSize²DCommand&, const Header&);
        ~SetMinSize²DCommand();

    private:
        Size2D   m_size = ZERO;
        
        SetMinSize²DCommand(const SetMinSize²DCommand&) = delete;
        SetMinSize²DCommand(SetMinSize²DCommand&&) = delete;
        SetMinSize²DCommand& operator=(const SetMinSize²DCommand&) = delete;
        SetMinSize²DCommand& operator=(SetMinSize²DCommand&&) = delete;
    };
}
