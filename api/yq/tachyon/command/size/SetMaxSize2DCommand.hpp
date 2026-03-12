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
    class SetMaxSize²DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize²DCommand, SizeCommand)
    public:
        SetMaxSize²DCommand(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize²DCommand(const Header&);
        SetMaxSize²DCommand(const SetMaxSize²DCommand&, const Header&);
        ~SetMaxSize²DCommand();

    private:
        Size2D   m_size = ZERO;
        
        SetMaxSize²DCommand(const SetMaxSize²DCommand&) = delete;
        SetMaxSize²DCommand(SetMaxSize²DCommand&&) = delete;
        SetMaxSize²DCommand& operator=(const SetMaxSize²DCommand&) = delete;
        SetMaxSize²DCommand& operator=(SetMaxSize²DCommand&&) = delete;
    };
}
