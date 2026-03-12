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
    class MultiplyMinSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize⁴DCommand, SizeCommand)
    public:
        MultiplyMinSize⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize⁴DCommand(const MultiplyMinSize⁴DCommand&, const Header&);
        MultiplyMinSize⁴DCommand(const Header&);
        ~MultiplyMinSize⁴DCommand();

    private:
        Vector4D  m_δ;
        
        MultiplyMinSize⁴DCommand(const MultiplyMinSize⁴DCommand&) = delete;
        MultiplyMinSize⁴DCommand(MultiplyMinSize⁴DCommand&&) = delete;
        MultiplyMinSize⁴DCommand& operator=(const MultiplyMinSize⁴DCommand&) = delete;
        MultiplyMinSize⁴DCommand& operator=(MultiplyMinSize⁴DCommand&&) = delete;
    };
}
