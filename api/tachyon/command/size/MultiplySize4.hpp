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
    class MultiplySize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize⁴, SizeCommand)
    public:
        MultiplySize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize⁴(const MultiplySize⁴&, const Header&);
        MultiplySize⁴(const Header&);
        ~MultiplySize⁴();

    private:
        Vector4D  m_δ;
        
        MultiplySize⁴(const MultiplySize⁴&) = delete;
        MultiplySize⁴(MultiplySize⁴&&) = delete;
        MultiplySize⁴& operator=(const MultiplySize⁴&) = delete;
        MultiplySize⁴& operator=(MultiplySize⁴&&) = delete;
    };
}
