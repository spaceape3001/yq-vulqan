////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplySize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize⁴DCommand, SizeCommand)
    public:
        MultiplySize⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize⁴DCommand(const MultiplySize⁴DCommand&, const Header&);
        MultiplySize⁴DCommand(const Header&);
        ~MultiplySize⁴DCommand();

    private:
        Vector4D  m_δ;
        
        MultiplySize⁴DCommand(const MultiplySize⁴DCommand&) = delete;
        MultiplySize⁴DCommand(MultiplySize⁴DCommand&&) = delete;
        MultiplySize⁴DCommand& operator=(const MultiplySize⁴DCommand&) = delete;
        MultiplySize⁴DCommand& operator=(MultiplySize⁴DCommand&&) = delete;
    };
}
