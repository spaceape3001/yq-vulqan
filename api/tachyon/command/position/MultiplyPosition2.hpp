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
    class MultiplyPosition² : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition², PositionCommand)
    public:
        MultiplyPosition²(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyPosition²(const MultiplyPosition²&, const Header&);
        MultiplyPosition²(const Header&);
        ~MultiplyPosition²();

    private:
        Vector2D  m_δ;
        
        MultiplyPosition²(const MultiplyPosition²&) = delete;
        MultiplyPosition²(MultiplyPosition²&&) = delete;
        MultiplyPosition²& operator=(const MultiplyPosition²&) = delete;
        MultiplyPosition²& operator=(MultiplyPosition²&&) = delete;
    };
}
