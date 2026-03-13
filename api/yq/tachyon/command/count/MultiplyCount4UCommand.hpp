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
    class MultiplyCount⁴UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount⁴UCommand, CountCommand)
    public:
        MultiplyCount⁴UCommand(const Header&, const Vector4U&);
    
        const Vector4U&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        unsigned  δz() const { return m_δ.z; }
        unsigned  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCount⁴UCommand(const MultiplyCount⁴UCommand&, const Header&);
        MultiplyCount⁴UCommand(const Header&);
        ~MultiplyCount⁴UCommand();

    private:
        Vector4U  m_δ;
        
        MultiplyCount⁴UCommand(const MultiplyCount⁴UCommand&) = delete;
        MultiplyCount⁴UCommand(MultiplyCount⁴UCommand&&) = delete;
        MultiplyCount⁴UCommand& operator=(const MultiplyCount⁴UCommand&) = delete;
        MultiplyCount⁴UCommand& operator=(MultiplyCount⁴UCommand&&) = delete;
    };
}
