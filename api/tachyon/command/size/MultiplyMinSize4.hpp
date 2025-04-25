////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize⁴, SizeCommand)
    public:
        MultiplyMinSize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize⁴(const MultiplyMinSize⁴&, const Header&);
        MultiplyMinSize⁴(const Header&);
        ~MultiplyMinSize⁴();

    private:
        Vector4D  m_δ;
        
        MultiplyMinSize⁴(const MultiplyMinSize⁴&) = delete;
        MultiplyMinSize⁴(MultiplyMinSize⁴&&) = delete;
        MultiplyMinSize⁴& operator=(const MultiplyMinSize⁴&) = delete;
        MultiplyMinSize⁴& operator=(MultiplyMinSize⁴&&) = delete;
    };
}
