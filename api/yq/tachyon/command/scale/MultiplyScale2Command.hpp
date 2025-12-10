////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale²Command : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale²Command, ScaleCommand)
    public:
        MultiplyScale²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyScale²Command(const MultiplyScale²Command&, const Header&);
        MultiplyScale²Command(const Header&);
        ~MultiplyScale²Command();

    private:
        Vector2D  m_δ;
        
        MultiplyScale²Command(const MultiplyScale²Command&) = delete;
        MultiplyScale²Command(MultiplyScale²Command&&) = delete;
        MultiplyScale²Command& operator=(const MultiplyScale²Command&) = delete;
        MultiplyScale²Command& operator=(MultiplyScale²Command&&) = delete;
    };
}
