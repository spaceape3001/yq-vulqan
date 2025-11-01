////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition²Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition²Command, PositionCommand)
    public:
        MultiplyPosition²Command(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyPosition²Command(const MultiplyPosition²Command&, const Header&);
        MultiplyPosition²Command(const Header&);
        ~MultiplyPosition²Command();

    private:
        Vector2D  m_δ;
        
        MultiplyPosition²Command(const MultiplyPosition²Command&) = delete;
        MultiplyPosition²Command(MultiplyPosition²Command&&) = delete;
        MultiplyPosition²Command& operator=(const MultiplyPosition²Command&) = delete;
        MultiplyPosition²Command& operator=(MultiplyPosition²Command&&) = delete;
    };
}
