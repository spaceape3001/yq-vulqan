////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition⁴ : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition⁴, PositionCommand)
    public:
        MultiplyPosition⁴(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition⁴(const MultiplyPosition⁴&, const Header&);
        MultiplyPosition⁴(const Header&);
        ~MultiplyPosition⁴();

    private:
        Vector4D  m_δ;
        
        MultiplyPosition⁴(const MultiplyPosition⁴&) = delete;
        MultiplyPosition⁴(MultiplyPosition⁴&&) = delete;
        MultiplyPosition⁴& operator=(const MultiplyPosition⁴&) = delete;
        MultiplyPosition⁴& operator=(MultiplyPosition⁴&&) = delete;
    };
}
