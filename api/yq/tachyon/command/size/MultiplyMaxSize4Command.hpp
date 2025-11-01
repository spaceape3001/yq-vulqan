////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize⁴Command, SizeCommand)
    public:
        MultiplyMaxSize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize⁴Command(const MultiplyMaxSize⁴Command&, const Header&);
        MultiplyMaxSize⁴Command(const Header&);
        ~MultiplyMaxSize⁴Command();

    private:
        Vector4D  m_δ;
        
        MultiplyMaxSize⁴Command(const MultiplyMaxSize⁴Command&) = delete;
        MultiplyMaxSize⁴Command(MultiplyMaxSize⁴Command&&) = delete;
        MultiplyMaxSize⁴Command& operator=(const MultiplyMaxSize⁴Command&) = delete;
        MultiplyMaxSize⁴Command& operator=(MultiplyMaxSize⁴Command&&) = delete;
    };
}
