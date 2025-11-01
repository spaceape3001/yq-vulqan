////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize²Command, SizeCommand)
    public:
        SetSize²Command(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize²Command(const Header&);
        SetSize²Command(const SetSize²Command&, const Header&);
        ~SetSize²Command();

    private:
        Size2D   m_size = ZERO;
        
        SetSize²Command(const SetSize²Command&) = delete;
        SetSize²Command(SetSize²Command&&) = delete;
        SetSize²Command& operator=(const SetSize²Command&) = delete;
        SetSize²Command& operator=(SetSize²Command&&) = delete;
    };
}
