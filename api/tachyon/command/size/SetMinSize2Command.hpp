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
    class SetMinSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize²Command, SizeCommand)
    public:
        SetMinSize²Command(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize²Command(const Header&);
        SetMinSize²Command(const SetMinSize²Command&, const Header&);
        ~SetMinSize²Command();

    private:
        Size2D   m_size = ZERO;
        
        SetMinSize²Command(const SetMinSize²Command&) = delete;
        SetMinSize²Command(SetMinSize²Command&&) = delete;
        SetMinSize²Command& operator=(const SetMinSize²Command&) = delete;
        SetMinSize²Command& operator=(SetMinSize²Command&&) = delete;
    };
}
