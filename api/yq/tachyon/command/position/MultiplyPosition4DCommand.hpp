////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition⁴DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition⁴DCommand, PositionCommand)
    public:
        MultiplyPosition⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        double  δw() const { return m_δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition⁴DCommand(const MultiplyPosition⁴DCommand&, const Header&);
        MultiplyPosition⁴DCommand(const Header&);
        ~MultiplyPosition⁴DCommand();

    private:
        Vector4D  m_δ;
        
        MultiplyPosition⁴DCommand(const MultiplyPosition⁴DCommand&) = delete;
        MultiplyPosition⁴DCommand(MultiplyPosition⁴DCommand&&) = delete;
        MultiplyPosition⁴DCommand& operator=(const MultiplyPosition⁴DCommand&) = delete;
        MultiplyPosition⁴DCommand& operator=(MultiplyPosition⁴DCommand&&) = delete;
    };
}
