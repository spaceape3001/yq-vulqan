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
    class MultiplySize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize⁴Command, SizeCommand)
    public:
        MultiplySize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize⁴Command(const MultiplySize⁴Command&, const Header&);
        MultiplySize⁴Command(const Header&);
        ~MultiplySize⁴Command();

    private:
        Vector4D  m_δ;
        
        MultiplySize⁴Command(const MultiplySize⁴Command&) = delete;
        MultiplySize⁴Command(MultiplySize⁴Command&&) = delete;
        MultiplySize⁴Command& operator=(const MultiplySize⁴Command&) = delete;
        MultiplySize⁴Command& operator=(MultiplySize⁴Command&&) = delete;
    };
}
