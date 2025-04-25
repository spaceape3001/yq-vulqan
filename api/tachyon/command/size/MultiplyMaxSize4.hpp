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
    class MultiplyMaxSize⁴ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize⁴, SizeCommand)
    public:
        MultiplyMaxSize⁴(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize⁴(const MultiplyMaxSize⁴&, const Header&);
        MultiplyMaxSize⁴(const Header&);
        ~MultiplyMaxSize⁴();

    private:
        Vector4D  m_δ;
        
        MultiplyMaxSize⁴(const MultiplyMaxSize⁴&) = delete;
        MultiplyMaxSize⁴(MultiplyMaxSize⁴&&) = delete;
        MultiplyMaxSize⁴& operator=(const MultiplyMaxSize⁴&) = delete;
        MultiplyMaxSize⁴& operator=(MultiplyMaxSize⁴&&) = delete;
    };
}
