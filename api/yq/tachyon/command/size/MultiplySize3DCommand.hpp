////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplySize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplySize³DCommand, SizeCommand)
    public:
        MultiplySize³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize³DCommand(const MultiplySize³DCommand&, const Header&);
        MultiplySize³DCommand(const Header&);
        ~MultiplySize³DCommand();

    private:
        Vector3D  m_δ;
        
        MultiplySize³DCommand(const MultiplySize³DCommand&) = delete;
        MultiplySize³DCommand(MultiplySize³DCommand&&) = delete;
        MultiplySize³DCommand& operator=(const MultiplySize³DCommand&) = delete;
        MultiplySize³DCommand& operator=(MultiplySize³DCommand&&) = delete;
    };
}
