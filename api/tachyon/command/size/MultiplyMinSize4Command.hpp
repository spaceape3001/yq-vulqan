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
    class MultiplyMinSize⁴Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize⁴Command, SizeCommand)
    public:
        MultiplyMinSize⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize⁴Command(const MultiplyMinSize⁴Command&, const Header&);
        MultiplyMinSize⁴Command(const Header&);
        ~MultiplyMinSize⁴Command();

    private:
        Vector4D  m_δ;
        
        MultiplyMinSize⁴Command(const MultiplyMinSize⁴Command&) = delete;
        MultiplyMinSize⁴Command(MultiplyMinSize⁴Command&&) = delete;
        MultiplyMinSize⁴Command& operator=(const MultiplyMinSize⁴Command&) = delete;
        MultiplyMinSize⁴Command& operator=(MultiplyMinSize⁴Command&&) = delete;
    };
}
