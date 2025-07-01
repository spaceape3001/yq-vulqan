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
    class MultiplyPosition⁴Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition⁴Command, PositionCommand)
    public:
        MultiplyPosition⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition⁴Command(const MultiplyPosition⁴Command&, const Header&);
        MultiplyPosition⁴Command(const Header&);
        ~MultiplyPosition⁴Command();

    private:
        Vector4D  m_δ;
        
        MultiplyPosition⁴Command(const MultiplyPosition⁴Command&) = delete;
        MultiplyPosition⁴Command(MultiplyPosition⁴Command&&) = delete;
        MultiplyPosition⁴Command& operator=(const MultiplyPosition⁴Command&) = delete;
        MultiplyPosition⁴Command& operator=(MultiplyPosition⁴Command&&) = delete;
    };
}
