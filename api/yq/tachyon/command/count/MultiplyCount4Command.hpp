////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount⁴Command : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount⁴Command, CountCommand)
    public:
        MultiplyCount⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        unsigned  δz() const { return m_δ.z; }
        unsigned  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCount⁴Command(const MultiplyCount⁴Command&, const Header&);
        MultiplyCount⁴Command(const Header&);
        ~MultiplyCount⁴Command();

    private:
        Vector4D  m_δ;
        
        MultiplyCount⁴Command(const MultiplyCount⁴Command&) = delete;
        MultiplyCount⁴Command(MultiplyCount⁴Command&&) = delete;
        MultiplyCount⁴Command& operator=(const MultiplyCount⁴Command&) = delete;
        MultiplyCount⁴Command& operator=(MultiplyCount⁴Command&&) = delete;
    };
}
