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
    class MultiplyMaxSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize⁴DCommand, SizeCommand)
    public:
        MultiplyMaxSize⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize⁴DCommand(const MultiplyMaxSize⁴DCommand&, const Header&);
        MultiplyMaxSize⁴DCommand(const Header&);
        ~MultiplyMaxSize⁴DCommand();

    private:
        Vector4D  m_δ;
        
        MultiplyMaxSize⁴DCommand(const MultiplyMaxSize⁴DCommand&) = delete;
        MultiplyMaxSize⁴DCommand(MultiplyMaxSize⁴DCommand&&) = delete;
        MultiplyMaxSize⁴DCommand& operator=(const MultiplyMaxSize⁴DCommand&) = delete;
        MultiplyMaxSize⁴DCommand& operator=(MultiplyMaxSize⁴DCommand&&) = delete;
    };
}
