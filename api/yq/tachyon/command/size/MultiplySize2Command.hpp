////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplySize²Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize²Command, SizeCommand)
    public:
        MultiplySize²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplySize²Command(const MultiplySize²Command&, const Header&);
        MultiplySize²Command(const Header&);
        ~MultiplySize²Command();

    private:
        Vector2D  m_δ;
        
        MultiplySize²Command(const MultiplySize²Command&) = delete;
        MultiplySize²Command(MultiplySize²Command&&) = delete;
        MultiplySize²Command& operator=(const MultiplySize²Command&) = delete;
        MultiplySize²Command& operator=(MultiplySize²Command&&) = delete;
    };
}
