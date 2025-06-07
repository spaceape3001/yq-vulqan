////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize²Command, SizeCommand)
    public:
        MultiplyMinSize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyMinSize²Command(const MultiplyMinSize²Command&, const Header&);
        MultiplyMinSize²Command(const Header&);
        ~MultiplyMinSize²Command();

    private:
        Vector2D  m_δ;
        
        MultiplyMinSize²Command(const MultiplyMinSize²Command&) = delete;
        MultiplyMinSize²Command(MultiplyMinSize²Command&&) = delete;
        MultiplyMinSize²Command& operator=(const MultiplyMinSize²Command&) = delete;
        MultiplyMinSize²Command& operator=(MultiplyMinSize²Command&&) = delete;
    };
}
