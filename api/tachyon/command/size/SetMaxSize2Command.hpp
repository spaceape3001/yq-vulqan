////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize²Command, SizeCommand)
    public:
        SetMaxSize²Command(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize²Command(const Header&);
        SetMaxSize²Command(const SetMaxSize²Command&, const Header&);
        ~SetMaxSize²Command();

    private:
        Size2D   m_size = ZERO;
        
        SetMaxSize²Command(const SetMaxSize²Command&) = delete;
        SetMaxSize²Command(SetMaxSize²Command&&) = delete;
        SetMaxSize²Command& operator=(const SetMaxSize²Command&) = delete;
        SetMaxSize²Command& operator=(SetMaxSize²Command&&) = delete;
    };
}
